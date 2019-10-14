type player = {
  mutable shape: Shapes.t,
  mutable speed: float,
};

let main = () => {
  open Inputs;

  let worldWidth = 700.0;
  let worldHeight = 500.0;
  let cameraOffset = Point.vector2(worldWidth /. 2.0, worldHeight /. 2.0);
  let game =
    Core.makeEngine(
      ~boundaries=(worldWidth, worldHeight),
      ~screenSizes=(worldWidth, worldHeight),
      ~offset=cameraOffset,
      (),
    );

  let worldToScreen = point =>
    point |> Camera.worldToScreenPoint(game.camera);

  let pl = {
    shape:
      Shapes.makeRect(
        ~position=Point.vector2(0.0, 0.0),
        ~size=(50.0, 50.0),
        ~color="red",
        (),
      ),
    speed: 6.0,
  };

  let plMove = () => {
    Shapes.(
      if (game.inputs.keyboard |> Keyboard.isDown(Keyboard.KeyS)) {
        Point.(position(pl.shape) + vector2(0.0, pl.speed))
        |> setPosition(pl.shape);
      }
    );
  };

  Core.looper(
    ~game,
    _ => {
      plMove();

      (game.context, pl.shape)
      |> Shapes.render(~pointTransformer=worldToScreen);

      game.context |> Debug.cameraInfo(~camera=game.camera);
    },
  );
};

main();