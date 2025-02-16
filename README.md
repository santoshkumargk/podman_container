# podman_container
Experiement with podman

podman build --no-cache -t helloworld-small-container -f src/SmallImage.dockerfile .
OR
podman build -t helloworld-small-container -f src/SmallImage.dockerfile .

echo "This is a configuration value" > /home/santosh/sandbox/podman/podman_container/config/config.txt

podman run --rm --privileged --entrypoint /app/helloworld -v /home/santosh/sandbox/podman/podman_container/config/config.txt:/app/config.txt helloworld-small-container /app/config.txt


Debugging:
podman run --rm --privileged -v /home/santosh/sandbox/podman/podman_container/config/config.txt:/app/config.txt -it helloworld-small-container sh

ls -l /app/config.txt
ls -l /app/helloworld
./helloworld /app/config.txt
