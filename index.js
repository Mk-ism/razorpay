import SocketIo from 'socket.io';
import ConnectionManager from './handlers/connectionManager';
import ChatManager from './handlers/chatManager';
import jwtAuth from "./middleware/userAuth";
import config from 'config';

var socketManager = {};

socketManager.init = (server) => {

  const io = SocketIo(server , {
    pingInterval: 4000,
    pingTimeout: 8000,
    cors: {
      origin: '*',
      methods: ["GET", "POST"],
      credentials: true
    }
  });
  io.use(jwtAuth);
  var connectionManager = new ConnectionManager();
  var chatManager = new ChatManager();
  io.sockets.on('connection', (socket) => {
    socket.on('disconnect', () => {
      console.log('disconnecting');
    });
    
    socket.on('pinging', 
    (connData)=> connectionManager.pinging(connData,socket));

    socket.on('joinRoom', 
    (chatData)=> connectionManager.joinRoom(chatData,socket));

    socket.on('createChatRoom', 
    ()=> connectionManager.createChatRoom(socket));

    socket.on('sendMessage', 
    (chatData)=> chatManager.sendMessage(chatData, socket));

    socket.on('getMessages',
    (chatData)=> chatManager.getMessages(chatData, socket));

  });
}


export default socketManager;
