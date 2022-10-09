import { ChatDB } from '../../models/Chat';
import { nanoid } from 'nanoid';

export default class ChatManager {

    async sendMessage (chatData, socket) {
      let { chatId, message, sender } = chatData;
      await ChatDB.create({chatid: chatId, message, sender, timestamp: Date.now(), id: nanoid()});
      socket.emit('messageReceived', {chatId, message, sender});
      socket.in(chatId).emit('messageReceived', {chatId, message, sender});
    }

    async getMessages (chatData, socket) {
      let { chatId } = chatData;
      const chats = await ChatDB.findAll({where:{chatid: chatId}});
      socket.emit('messagesUpdated', {chats});
    }
}
