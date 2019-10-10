open Webapi.Dom;

type t = {mutable position: Point.t};

let createMouseControll = canvas => {
  let mouseState = {position: Point.vector2(0.0, 0.0)};

  canvas
  |> Element.addMouseMoveEventListener(event =>
       mouseState.position =
         Point.vector2(
           float_of_int(MouseEvent.clientX(event)),
           float_of_int(MouseEvent.clientX(event)),
         )
     );

  mouseState;
};

let getPosition = (mouseState: t): Point.t => mouseState.position;