bashrc 정리
2024.08.12 기준
```
####### Theo
alias hum='source /opt/ros/humble/setup.bash'
alias eb='gedit ~/.bashrc'
alias cb='colcon build'
alias su='. install/setup.bash'
alias inst='. install/setup.bash'

##### GIT
alias pull='git pull origin main'
alias push='git add . && git commit -m "new Ubuntu commit" && git push -u origin main'

##### PX4
alias qgc='cd && cd Downloads/ && ./QGroundControl.AppImage'
alias upload='cd && cd uploadPX4/PX4-Autopilot/ && make px4_fmu-v6x_default upload'

##### PX4 GZ
# Set the plugin path so Gazebo finds our model and sim
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:$HOME/src/sitl_gazebo/Build
# Set the model path so Gazebo finds the airframes
export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:$HOME/src/sitl_gazebo/models
# Disable online model lookup since this is quite experimental and unstable
export GAZEBO_MODEL_DATABASE_URI=""
# Set path to sitl_gazebo repository
export SITL_GAZEBO_PATH=$HOME/src/sitl_gazebo

### Disable GUI
alias nogui='sudo systemctl start multi-user.target'
alias gui='sudo systemctl start graphical.target'

### Obsidian
alias obs='~/startup.sh'
alias pobs='cd && cd Opsidian_Manipulator/ && push'

### Iron
alias iron='source /opt/ros/iron/setup.bash'
### NAV2 GPS 예제를 위한 가제보 맵
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/gazebo_models

### MySQL
alias sql='sudo mysql -u root -p'
```
24.07.22 기준
```
####### Theo
alias hum='source /opt/ros/humble/setup.bash'
alias eb='gedit ~/.bashrc'
alias cb='colcon build'
alias su='. install/setup.bash'

##### GIT
alias pull='git pull origin main'
alias push='git add . && git commit -m "new Ubuntu commit" && git push -u origin main'

##### PX4
alias qgc='cd && cd Downloads/ && ./QGroundControl.AppImage'
alias upload='cd && cd uploadPX4/PX4-Autopilot/ && make px4_fmu-v6x_default upload'

##### PX4 GZ
# Set the plugin path so Gazebo finds our model and sim
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:$HOME/src/sitl_gazebo/Build
# Set the model path so Gazebo finds the airframes
export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:$HOME/src/sitl_gazebo/models
# Disable online model lookup since this is quite experimental and unstable
export GAZEBO_MODEL_DATABASE_URI=""
# Set path to sitl_gazebo repository
export SITL_GAZEBO_PATH=$HOME/src/sitl_gazebo

### Disable GUI
alias nogui='sudo systemctl start multi-user.target'
alias gui='sudo systemctl start graphical.target'

### Obsidian
alias obs='~/startup.sh'
alias pobs='cd && cd Opsidian_Manipulator/ && push'

### Iron 설치
alias iron='source /opt/ros/iron/setup.bash'
```