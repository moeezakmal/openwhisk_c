#!/bin/bash

# Delete the 'openwhisk' namespace
kubectl delete namespace openwhisk

# Extract the OpenWhisk CLI
tar -xvf OpenWhisk_CLI-latest-linux-386.tgz

# Move the 'wsk' executable to '/usr/local/bin'
sudo mv wsk /usr/local/bin/wsk

# Label the nodes
kubectl label node gke-openwhisk-cluster-experiment-pool-0968ed96-h484 openwhisk-role=core
kubectl label nodes gke-openwhisk-cluster-experiment-pool-0968ed96-v9l7 gke-openwhisk-cluster-experiment-pool-0968ed96-zvd9 openwhisk-role=invoker

# Create the 'openwhisk' namespace
kubectl create namespace openwhisk

# Change directory to 'openwhisk-deploy-kube'
cd openwhisk-deploy-kube

# Install OpenWhisk using Helm
helm install ./helm/openwhisk --namespace=openwhisk --generate-name -f mycluster.yaml

