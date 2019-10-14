open Webapi.Dom;
open Prelude;

type t = {keyMap: Js.Dict.t(bool)};

[@bs.get] external keyCode: KeyboardEvent.t => int = "";

[@bs.deriving jsConverter]
type keys =
  | [@bs.as 39] RightArrow
  | [@bs.as 37] LeftArrow
  | [@bs.as 38] TopArrow
  | [@bs.as 40] DownArrow
  | [@bs.as 83] KeyS
  | [@bs.as 68] KeyD
  | [@bs.as 65] KeyA
  | [@bs.as 87] KeyW;

let makeKeyBoardControll = () => {
  let state = {keyMap: Js.Dict.empty()};

  document
  |> Document.addKeyDownEventListener(event => {
       KeyboardEvent.preventDefault(event);
       Js.Dict.set(state.keyMap, intToString(keyCode(event)), true);
     });

  document
  |> Document.addKeyUpEventListener(event => {
       KeyboardEvent.preventDefault(event);
       Js.Dict.set(state.keyMap, intToString(keyCode(event)), false);
     });

  state;
};

let isDown = (key: keys, state: t) =>
  key
  |> keysToJs
  |> intToString
  |> Js.Dict.get(state.keyMap)
  |> Option.unwrapOr(false);