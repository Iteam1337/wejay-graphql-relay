module Query = [%relay.query
  {|
  query AppQuery {
    ...NowPlaying_query
    ...Queue_query
  }
|}
];

module Style = {
  open Css;

  let container =
    merge([
      "mt-16",
      style([
        display(`grid),
        gridColumnGap(`px(48)),
        gridTemplateColumns([
          `fr(1.0),
          `px(20),
          `px(300),
          `px(600),
          `px(20),
          `fr(1.0),
        ]),
      ]),
    ]);

  let nowPlaying = style([gridColumn(3, 4)]);

  let queue = style([gridColumn(4, 5)]);
};

[@react.component]
let make = () => {
  let query = Query.use(~variables=(), ());

  <div className=Style.container>
    <div className=Style.nowPlaying> <NowPlaying query /> </div>
    <div className=Style.queue> <Queue query /> </div>
  </div>;
};
