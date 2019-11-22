type t;
type fragmentRef;
type fragmentRefSelector('a) = {.. "__$fragment_ref__Queue_query": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type fragment = {
  .
  "currentQueue":
    array({
      .
      "title": string,
      "id": string,
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
  "name": "Queue_query",
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
      "name": "currentQueue",
      "storageKey": null,
      "args": null,
      "concreteType": "Track",
      "plural": true,
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
} |}
];
