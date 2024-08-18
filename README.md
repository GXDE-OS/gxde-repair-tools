# GXDE Repair Tools
> __A useful tools for repair & clean your GXDE OS.__

### Project Goals
* [x] Grub repair
* [x] DPKG wrong status repair
* [x] Password reset
* [x] APT cache clear

### Build from source
#### Requirements
* Qt5 with components: Core, Widget, Concurrent
* libdtkwidget2-dev
* cmake 3.8.6+
* pkg-config

```
git clone git@github.com:sbwtw/gxde-repair-tools.git
cd gxde-repair-tools
cmake ..
make -j4
sudo make install
```

### LICENSE
GXDE Repair Tools is licensed under GPL