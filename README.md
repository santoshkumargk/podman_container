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
echo "This is a configuration value" > /path/to/podman_container/config/config.txt
```

## Running the Container

> **Note:** The following command is obsolete:
> ```sh
> podman run --rm --privileged --entrypoint /app/helloworld \
>   -v /path/to/podman_container/config/config.txt:/app/config.txt \
>   helloworld-small-container /app/config.txt
> ```

```sh
podman run --rm --privileged --entrypoint /app/helloworld \
  -v /path/to/podman_container/config/config.txt:/app/config.txt \
  -v /path/to/podman_container/logs:/app/logs \
  helloworld-small-container /app/config.txt
```

## Debugging
```sh
podman run --rm --privileged -v /path/to/podman_container/config/config.txt:/app/config.txt -it helloworld-small-container sh
```

### Inside the Container
```sh
ls -l /app/config.txt
ls -l /app/helloworld
./helloworld /app/config.txt
```

## Managing the Container

### Stopping the Container
```sh
podman stop <container_id>
```

### Checking if the Container is Running
```sh
podman ps
```

### Deleting the Container
```sh
podman rm <container_id>
```

### Removing the Image
```sh
podman rmi helloworld-small-container
```

## Viewing Logs
Logs can also be viewed using the `podman logs` command:
```sh
podman logs <container_id>
```
