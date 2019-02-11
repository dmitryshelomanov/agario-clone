type t = {
  x: float,
  y: float,
};

let vector2 = (x, y) => {x, y};

let distance = (p, p1) => {
  let dirX = p1.x -. p.x;
  let dirY = p1.y -. p.y;

  Js.Math.sqrt(dirX *. dirX +. dirY *. dirY);
};

let add = (p, p1) => vector2(p1.x +. p.x, p1.y +. p.y);

let subtract = (p, p1) => vector2(p1.x -. p.x, p1.y -. p.y);

let multiplication = (p, n) => vector2(p.x *. n, p.y *. n);

let divided = (p, n) => vector2(p.x /. n, p.y /. n);
