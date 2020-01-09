/* @generated */

module Unions = {};

module Types = {
  type currentTrack = {
    artist: string,
    cover: option(string),
    title: string,
  };
};

open Types;

type fragment = {
  playerState: SchemaAssets.Enum_PlayerState.t,
  currentTrack: option(currentTrack),
};

module FragmentConverters: {} = {};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(array((int, string))) = [%raw
    {| {"playerState":[[2,"enum_PlayerState"]],"currentTrack":[[0,""]],"currentTrack_cover":[[0,""]]} |}
  ];
  let fragmentConverterMap = {
    "enum_PlayerState": SchemaAssets.Enum_PlayerState.unwrap,
  };
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__NowPlaying_query": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type operationType = ReasonRelay.fragmentNode;

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
