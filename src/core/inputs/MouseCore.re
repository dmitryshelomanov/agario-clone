open Webapi.Dom;

type t = {
  mutable position: Point.t,
  mutable isMouseOver: bool,
  mutable isLeftDown: bool,
};

let createMouseControll = canvas => {
  let mouseState = {
    position: Point.vector2(0.0, 0.0),
    isMouseOver: false,
    isLeftDown: false,
  };

  canvas
  |> Element.addMouseMoveEventListener(event =>
       mouseState.position =
         Point.vector2(
           float_of_int(MouseEvent.clientX(event)),
           float_of_int(MouseEvent.clientY(event)),
         )
     );

  canvas
  |> Element.addMouseOverEventListener(_ => mouseState.isMouseOver = true);
  canvas
  |> Element.addMouseOutEventListener(_ => mouseState.isMouseOver = false);

  canvas
  |> Element.addMouseDownEventListener(_ => mouseState.isLeftDown = true);
  canvas |> Element.addMouseUpEventListener(_ => mouseState.isLeftDown = false);

  mouseState;
};

let getMouseOverState = (mouseState: t) => mouseState.isMouseOver;

let getMousePosition = (mouseState: t) => mouseState.position;

let getMouseLeftDownState = (mouseState: t) =>
  mouseState.isLeftDown && getMouseOverState(mouseState);