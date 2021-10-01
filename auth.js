{ verify } from "jsonwebtoken";
import config from "config";

let jwtAuth = async (socket, next) => {
  if (socket.handshake.query && socket.handshake.query.token) {
    verify(socket.handshake.query.token, config.get("jwtSecret"), function (
      err,
      decoded
    ) {
      if (err) return next(new Error("Authentication error"));
      socket.decoded = decoded;
      next();
    });
  } else {
    next(new Error("Authentication error"));
  }
}

export default jwtAuth;
