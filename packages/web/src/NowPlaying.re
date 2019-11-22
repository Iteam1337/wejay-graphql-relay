module NowPlayingFragment = [%relay.fragment
  {|
  fragment NowPlaying_query on Query {
    playerState
    currentTrack {
      artist
      cover
      title
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let nowPlaying = NowPlayingFragment.use(queryRef);

  switch (
    nowPlaying##playerState->SchemaAssets.Enum_PlayerState.unwrap,
    nowPlaying##currentTrack->Js.Nullable.toOption,
  ) {
  | (`Playing, Some(track)) =>
    <div>
      {switch (track##cover->Js.Nullable.toOption) {
       | Some(src) => <img className="rounded shadow-lg" src />
       | None => React.null
       }}
      <div className="mt-5 text-lg font-semibold">
        {React.string(track##title)}
      </div>
      <div className="text-gray-500 mt-1">
        {React.string(track##artist)}
      </div>
    </div>
  | _ => React.null
  };
};
