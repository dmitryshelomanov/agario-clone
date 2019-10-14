let cameraInfo = (~camera: Camera.t, ctx) => {
  let (w, h) = camera.size;

  let texts = [|
    "Camera (" ++ string_of_float(w) ++ " x " ++ string_of_float(h) ++ ")",
    "Position X: "
    ++ string_of_float(camera.position.x)
    ++ " Y: "
    ++ string_of_float(camera.position.y),
    "Offset X: "
    ++ string_of_float(camera.offset.x)
    ++ " Y: "
    ++ string_of_float(camera.offset.y),
  |];

  ctx
  |> Draw.(
       renderTexsts(
         ~point=Point.vector2(10.0, 15.0),
         ~texts,
         ~style={font: "15px serif", fill: "black", align: `Start},
         ~lineHeight=20.0,
       )
     );
};