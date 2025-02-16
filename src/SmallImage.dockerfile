# Stage 1: Build the application
FROM alpine:latest AS builder

# Install build dependencies
RUN apk add --no-cache g++ make

WORKDIR /app

# Copy the source file from the build context
COPY src/helloworld.cpp .

# Compile the source file
RUN g++ -o helloworld helloworld.cpp

# Ensure the binary has executable permissions
RUN chmod +x helloworld

# Stage 2: Create a smaller runtime image
FROM alpine:latest

# Install runtime dependencies
RUN apk add --no-cache libstdc++

WORKDIR /app

# Copy the compiled binary from the builder stage
COPY --from=builder /app/helloworld .

# Set the command to run the binary
CMD ["./helloworld"]