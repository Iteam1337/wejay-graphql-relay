module QueueFragment = [%relay.fragment
  {|
  fragment Queue_query on Query {
    playerState
    currentQueue {
      artist
      cover
      id
      title
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let queue = QueueFragment.use(queryRef);

  switch (
    queue##playerState->SchemaAssets.Enum_PlayerState.unwrap,
    Belt.Array.length(queue##currentQueue),
  ) {
  | (_, 0) => <div> {React.string("Nothing queued")} </div>
  | (`Playing, _) =>
    <div>
      <h2 className="font-semibold pb-4 mb-4 border-b border-gray-300">
        {React.string("Upcoming tracks")}
      </h2>
      {queue##currentQueue
       ->Belt.Array.map(track =>
           <div className="flex items-center mb-4" key=track##id>
             {switch (track##cover->Js.Nullable.toOption) {
              | Some(src) =>
                <div className="w-12">
                  <img className="rounded-sm w-full shadow-md" src />
                </div>
              | None => React.null
              }}
             <div className="ml-5">
               <div className="text-gray-700 text-sm">
                 {React.string(track##title)}
               </div>
               <div className="text-gray-500 text-sm">
                 {React.string(track##artist)}
               </div>
             </div>
           </div>
         )
       ->React.array}
    </div>
  | _ => React.null
  };
};
