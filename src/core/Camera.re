open Webapi.Canvas;
open Point;

type t = {
  mutable position: Point.t,
  mutable offset: Point.t,
  width: float,
  height: float,
  screen: Canvas2d.t,
};

type coordinates =
  | GLOBAL_COORD
  | LOCAL_COORD;

let createCamera =
    (
      ~position=Point.vector2(0.0, 0.0),
      ~offset=Point.vector2(0.0, 0.0),
      ctx: Canvas2d.t,
    ) => {
  {
    position,
    offset,
    width: Canvas.context2dToJsObj(ctx)##canvas##width,
    height: Canvas.context2dToJsObj(ctx)##canvas##height,
    screen: ctx,
  };
};

let move = (~point, camera) => {
  camera.position = plus(camera.position, point);
};

let computedNextPositionByCamera = (~point, ~coord: coordinates, camera) => {
  switch (coord) {
  | GLOBAL_COORD => plus(minus(point, camera.position), camera.offset)
  | LOCAL_COORD => plus(point, camera.offset)
  };
};