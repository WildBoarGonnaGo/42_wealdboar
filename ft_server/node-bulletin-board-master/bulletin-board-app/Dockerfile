FROM node:12.19.0
WORKDIR /app
ENV NODE_ENV=production
COPY package.json .
RUN npm install
COPY . .
EXPOSE 8080
CMD [ "npm", "start" ]
