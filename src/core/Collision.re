type sideOfBoundaries =
  | Left(float)
  | Right(float);

let outOfBoundaries = (side, boundaryValue) =>
  switch (side) {
  | Left(poitValue) => boundaryValue > poitValue
  | Right(poitValue) => boundaryValue < poitValue
  };
