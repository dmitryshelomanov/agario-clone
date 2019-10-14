type t = {
  mutable position: Point.t,
  mutable offset: Point.t,
  size: Size.t,
};

let make =
    (
      ~position=Point.vector2(0.0, 0.0),
      ~offset=Point.vector2(0.0, 0.0),
      ~size,
      (),
    ) => {
  {position, offset, size};
};

let move = (~velocity: Point.t, camera) => {
  camera.position = Point.(camera.position + velocity);
};

let followTo = (~target: Point.t, ~time: float, camera) => {
  let {position} = camera;

  camera.position = time |> Point.moveTo(~point=position, ~target);
};

let screenToWorldPoint = (camera, point) =>
  Point.(point + camera.position - camera.offset);

let worldToScreenPoint = (camera, point) =>
  Point.(point - camera.position + camera.offset);

let inViewport = (~point: Point.t, camera) => {
  let {position, size} = camera;
  let (width, height) = size;

  let inX = point.x > position.x && point.x < width +. position.x;
  let inY = point.y > position.y && point.y < height +. position.y;

  inX && inY;
};