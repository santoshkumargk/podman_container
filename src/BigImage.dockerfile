FROM gcc:latest

WORKDIR /app

COPY src/helloworld.cpp .

RUN g++ -o helloworld helloworld.cpp

CMD ["./helloworld"]