# podman_container
Experiment with podman

## Building the Container
```sh
podman build --no-cache -t helloworld-small-container -f src/SmallImage.dockerfile .
# OR
podman build -t helloworld-small-container -f src/SmallImage.dockerfile .
```

## Configuration
```sh
echo "This is a configuration value" > /home/santosh/sandbox/podman/podman_container/config/config.txt
```

## Running the Container
```sh
podman run --rm --privileged --entrypoint /app/helloworld \
  -v /home/santosh/sandbox/podman/podman_container/config/config.txt:/app/config.txt \
  helloworld-small-container /app/config.txt
```

```sh
podman run --rm --privileged --entrypoint /app/helloworld \
  -v /home/santosh/sandbox/podman/podman_container/config/config.txt:/app/config.txt \
  -v /home/santosh/sandbox/podman/podman_container/logs:/app/logs \
  helloworld-small-container /app/config.txt
```

## Debugging
```sh
podman run --rm --privileged -v /home/santosh/sandbox/podman/podman_container/config/config.txt:/app/config.txt -it helloworld-small-container sh
```

### Inside the Container
```sh
ls -l /app/config.txt
ls -l /app/helloworld
./helloworld /app/config.txt
```
