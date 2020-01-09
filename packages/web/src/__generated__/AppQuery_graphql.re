/* @generated */

module Unions = {};

module Types = {};

type response = {
  __wrappedFragment__NowPlaying_query: ReasonRelay.wrappedFragmentRef,
  __wrappedFragment__Queue_query: ReasonRelay.wrappedFragmentRef,
};
type variables = unit;

module FragmentConverters: {
  let unwrapFragment_response:
    response =>
    {
      .
      "__$fragment_ref__NowPlaying_query": NowPlaying_query_graphql.t,
      "__$fragment_ref__Queue_query": Queue_query_graphql.t,
    };
} = {
  external unwrapFragment_response:
    response =>
    {
      .
      "__$fragment_ref__NowPlaying_query": NowPlaying_query_graphql.t,
      "__$fragment_ref__Queue_query": Queue_query_graphql.t,
    } =
    "%identity";
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(array((int, string))) = [%raw {| {} |}];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(array((int, string))) = [%raw {| {} |}];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "artist",
  "args": null,
  "storageKey": null
},
v1 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "cover",
  "args": null,
  "storageKey": null
},
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "title",
  "args": null,
  "storageKey": null
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "AppQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "FragmentSpread",
        "name": "NowPlaying_query",
        "args": null
      },
      {
        "kind": "FragmentSpread",
        "name": "Queue_query",
        "args": null
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "AppQuery",
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
          (v0/*: any*/),
          (v1/*: any*/),
          (v2/*: any*/),
          (v3/*: any*/)
        ]
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
          (v0/*: any*/),
          (v1/*: any*/),
          (v3/*: any*/),
          (v2/*: any*/)
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "AppQuery",
    "id": null,
    "text": "query AppQuery {\n  ...NowPlaying_query\n  ...Queue_query\n}\n\nfragment NowPlaying_query on Query {\n  playerState\n  currentTrack {\n    artist\n    cover\n    title\n    id\n  }\n}\n\nfragment Queue_query on Query {\n  playerState\n  currentQueue {\n    artist\n    cover\n    id\n    title\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
