type pointType = 
  | WorldCoord(Point.t)
  | ScreenCoord(Point.t);

let screenCoordToWorld = (p, origin) =>
  switch (p) {
  | ScreenCoord(point) => WorldCoord(Point.add(origin, point))
  | _ => failwith("[screenCoordToWorld]: point must be ScreenCoord")
  };

let worldCoordToScreen = (p, origin) =>
  switch (p) {
  | WorldCoord(point) => ScreenCoord(Point.subtract(origin, point))
  | _ => failwith("[worldCoordToScreen]: point must be WorldCoord")
  };

let unwrapPoint = (p) =>
  switch (p) {
  | ScreenCoord(point) => point
  | WorldCoord(point) => point
  };
