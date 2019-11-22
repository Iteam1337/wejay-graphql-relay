type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__NowPlaying_query": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type fragment = {
  .
  "currentTrack":
    Js.Nullable.t({
      .
      "title": string,
      "cover": Js.Nullable.t(string),
      "artist": string,
    }),
  "playerState": SchemaAssets.Enum_PlayerState.wrapped,
};
type operationType = ReasonRelay.fragmentNode;

module Unions = {};

let node: operationType = [%bs.raw
  {| {
  "kind": "Fragment",
  "name": "NowPlaying_query",
  "type": "Query",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "playerState",
      "args": null,
      "storageKey": null
    },
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
          "name": "title",
          "args": null,
          "storageKey": null
        }
      ]
    }
  ]
} |}
];
