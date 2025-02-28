# podman_container
Experiment with podman

## Dependencies
Ensure you have Podman installed on your system. You can install Podman using the following commands:

### On Fedora
```sh
sudo dnf install -y podman
```

### On Ubuntu
```sh
sudo apt-get update
sudo apt-get install -y podman
```

### On macOS
```sh
brew install podman
```

## Building the Container

Navigate to the base directory of the cloned repository:
```sh
cd /path/to/podman_container
```

### Using SmallImage.dockerfile
> **Note:** Using `SmallImage.dockerfile` results in an image size of approximately 10-20MB.
```sh
podman build --no-cache -t helloworld-small-container -f src/SmallImage.dockerfile .
# OR
podman build -t helloworld-small-container -f src/SmallImage.dockerfile .
```

### Using BigImage.dockerfile
> **Note:** Using `BigImage.dockerfile` results in an image size of approximately 1-2GB.
```sh
podman build --no-cache -t helloworld-big-container -f src/BigImage.dockerfile .
# OR
podman build -t helloworld-big-container -f src/BigImage.dockerfile .
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

## Viewing Logs

### When the Log Path is Mounted
If the log path is mounted, you can directly view the logs on the host system:
```sh
cat /path/to/podman_container/logs/log.txt
```

### When the Log Path is Not Mounted
To get logs from a running or stopped container when the log path is not mounted:
```sh
podman ps -a
```
Example output:
```
CONTAINER ID  IMAGE                           COMMAND               CREATED         STATUS                     PORTS  NAMES
d1f2e5783d85  localhost/helloworld-small-container:latest  ./helloworld  40 minutes ago  Exited (0) 10 minutes ago         helloworld-container
```
```sh
podman cp d1f2e5783d85:/app/logs/log.txt /path/to/podman_container/logs/log.txt
cat /path/to/podman_container/logs/log.txt
```

If you want to inspect running container logs without copying when the log path is not mounted:
```sh
podman exec -it helloworld-container cat /app/logs/log.txt
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

## Network Configuration

### Accessing the Complete Host Network
To access the complete host network, use the `--network host` option:
```sh
podman run --rm --privileged --network host --entrypoint /app/helloworld \
  -v /path/to/podman_container/config/config.txt:/app/config.txt \
  -v /path/to/podman_container/logs:/app/logs \
  helloworld-small-container /app/config.txt
```

### Mapping Certain Ports
To map certain ports, use the `-p` option:
```sh
podman run --rm --privileged -p <host_port>:<container_port> --entrypoint /app/helloworld \
  -v /path/to/podman_container/config/config.txt:/app/config.txt \
  -v /path/to/podman_container/logs:/app/logs \
  helloworld-small-container /app/config.txt
```

## Running Podman Container as a Systemd Service

### Create the Container with a Certain Name
```sh
podman create --name helloworld-container --privileged --entrypoint /app/helloworld \
  -v /path/to/podman_container/config/config.txt:/app/config.txt \
  -v /path/to/podman_container/logs:/app/logs \
  helloworld-small-container /app/config.txt
```

### Generate the Service File
```sh
podman generate systemd --name helloworld-container > ./systemd/helloworld-container-original.service
```

### Modify the Service File
1. Remove `PIDFile`
2. Remove `RequiresMountsFor`
2. Change `Type=simple`
3. Add `User=username` (Note: Should be the user used to create the container)

### Copy the Service File
Rename systemd/helloworld-container-original.service to helloworld-container.service.
```sh
sudo cp ./systemd/helloworld-container.service /etc/systemd/system/
sudo systemctl daemon-reload
```

### Start the Container as a Systemd Service
```sh
sudo systemctl start helloworld-container
```

### Stop the Container as a Systemd Service
```sh
sudo systemctl stop helloworld-container
```

### Check the Status of the Container as a Systemd Service
```sh
sudo systemctl status helloworld-container
```

### Monitor the Systemd Service Logs
```sh
journalctl -u helloworld-container.service -f
```