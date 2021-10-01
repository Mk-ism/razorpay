import express, { json } from 'express';
import connectDB from './config/dbConnector';
import auth from './routes/api/auth';
import config from 'config';
import cors from 'cors';
import socketManager from './sockets';
import http from 'http';
//import * as https from 'https';
//import fs from 'fs';

import { ChatData } from './models/Chat';

const PORT = config.get('serverPort');

//TODO: Integrate testing!

//**********************************Inits**********************************/
const app = express();
app.use(express.json());
connectDB().then(sequelize=>ChatData(sequelize));
app.use(cors());
app.use(json({ extended: false }));

//**********************************Routes**********************************/
app.use('/api/user', auth);

const server = http.createServer(app);
// const server = https.createServer({
//   key: fs.readFileSync('key.pem'),
//   cert: fs.readFileSync('cert.pem')
// }, app);

socketManager.init(server);

server.listen(PORT, () => {
  console.log('Go!');
});
