#!/bin/bash

# Lancer le conteneur Docker sans l'option -t ou --tty
sudo docker run -v /home/enzo/delivry/B-PSU-200-LIL-2-1-42sh-enzo.boron:/usr/data -i epitechcontent/epitest-docker:latest << EOF

# Commandes à exécuter à l'intérieur du conteneur Docker
cd ..
cd data
make test

# Sortir du conteneur Docker
exit

EOF
