# install.packages("tensorflow")
# install.packageS("keras")
library(tensorflow)
library(keras)
# follow directions for equivalent installation and virtual environment set-up in Python
# refer to:
# https://www.tensorflow.org/install/pip
# https://www.tensorflow.org/guide/keras 
Sys.which('virtualenv')
file.exists('/usr/local/bin/virtualenv')
Sys.setenv(TENSORFLOW_PYTHON="/usr/local/bin/python3")
install_tensorflow()
install_keras()
# updated Mar 7, 2019; prior last update/creation was Apr 17, 2018