type response = {
  .
  "__$fragment_ref__NowPlaying_query": NowPlaying_query_graphql.t,
};
type variables = unit;
type operationType = ReasonRelay.queryNode;

module Unions = {};

let node: operationType = [%bs.raw
  {| {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "NowPlayingRefetchQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "FragmentSpread",
        "name": "NowPlaying_query",
        "args": null
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "NowPlayingRefetchQuery",
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "currentTrack",
        "storageKey": null,
        "args": null,
        "concreteType": "Track",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "album",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "artist",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "cover",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "id",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "title",
            "args": null,
            "storageKey": null
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "NowPlayingRefetchQuery",
    "id": null,
    "text": "query NowPlayingRefetchQuery {\n  ...NowPlaying_query\n}\n\nfragment NowPlaying_query on Query {\n  currentTrack {\n    album\n    artist\n    cover\n    id\n    title\n  }\n}\n",
    "metadata": {
      "derivedFrom": "NowPlaying_query",
      "isRefetchableQuery": true
    }
  }
} |}
];
