import Chat from '../../models/Chat';
import { nanoid } from 'nanoid';
import { errorWrapper } from '../../utils/consts';

export default class ConnectionManager {

    async pinging (connData, socket) {
        const { chatId } = connData;
        socket.emit('pingu', {chatId});
        socket.in(chatId).emit('pingu', {chatId});
    }

    async joinRoom (chatData, socket) {
      const { chatId } = chatData;
      const chat = await Chat.findById(chatId);
      if(!chat)
        return socket.emit('err', errorWrapper('Room Not Found'));
      await socket.join(chatId);
      socket.emit('chatJoined', chatId);
      socket.in(chatId).emit('partnerJoined', chatId);
      return;
    }

    async createChatRoom (socket) {
      let chatId = nanoid();
      while( await Chat.findById(chatId) !== null) {
        chatId = nanoId();
      }
      const chat = new Chat({_id:chatId});
      await chat.save();
      await socket.join(chatId);
      socket.emit('chatRoomCreated', {chatId});
    }

}
