type t = {
  x: float,
  y: float,
};

let vector2 = (x, y) => {x, y};

let magnitude = ({x, y}) => Js.Math.sqrt(x *. x +. y *. y);

let distance = (p, p1) => vector2(p1.x -. p.x, p1.y -. p.y) |> magnitude;

let add = (p, p1) => vector2(p1.x +. p.x, p1.y +. p.y);

let subtract = (p, p1) => vector2(p1.x -. p.x, p1.y -. p.y);

let multiplication = ({x, y}, n) => vector2(x *. n, y *. n);

let divided = ({x, y}, n) => vector2(x /. n, y /. n);

let normalize = p =>
  switch (p |> magnitude) {
  | 0.0 => p
  | len => divided(p, len)
  };

let negative = p => multiplication(p, -.1.0);
