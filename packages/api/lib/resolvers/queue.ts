import { gql } from 'apollo-server-express'
import { pubsub } from '../server'
import {
  QueryResolvers,
  MutationResolvers,
  SubscriptionResolvers,
  PlayerState,
} from '../__generated__/graphql'
import { Sonos } from 'sonos'

const device = new Sonos('192.168.110.175')

const TRACK_ADDED = 'TRACK_ADDED'

export const typeDefs = gql`
  type Track {
    album: String!
    artist: String!
    cover: String
    id: ID!
    title: String!
  }

  input TrackInput {
    title: String!
    artist: String!
    album: String!
  }

  enum PlayerState {
    Playing
    Stopped
    Paused
    UnknownState
  }

  extend type Query {
    playerState: PlayerState!
    currentTrack: Track
    currentQueue: [Track!]!
  }

  extend type Mutation {
    addTrack(input: TrackInput!): [Track!]!
  }
`

interface Resolvers {
  Query: QueryResolvers
  Mutation: MutationResolvers
  Subscription: SubscriptionResolvers
}

export const resolvers: Resolvers = {
  Query: {
    _empty: () => '',

    playerState: async () => {
      const state = await device.getCurrentState()

      switch (state) {
        case 'stopped':
          return 'Stopped' as PlayerState
        case 'playing':
          return 'Playing' as PlayerState
        case 'paused':
          return 'Paused' as PlayerState
        default:
          return 'UnknownState' as PlayerState
      }
    },

    currentTrack: async () => {
      const current = await device.currentTrack()

      return {
        ...current,
        id: current.uri,
        cover: current.albumArtURL,
      }
    },

    currentQueue: async () => {
      const current = await device.currentTrack()
      const queue = await device.getQueue()

      return queue.items.slice(current.queuePosition).map((item: any) => ({
        ...item,
        cover: item.albumArtURI,
      }))
    },
  },

  Mutation: {
    _empty: () => '',
    addTrack: (_, { input }) => {
      pubsub.publish(TRACK_ADDED, { trackAdded: input })

      return []
    },
  },

  Subscription: {
    trackAdded: {
      subscribe: () => pubsub.asyncIterator([TRACK_ADDED]),
    },
  },
}

