# ROOT

## access
xhost +si:localuser:name

## github automation
git config --global credential.helper manager

## GCM - git credential manager
#
Debian package
Install

Download the latest .deb package*, and run the following:

sudo dpkg -i <path-to-package>
git-credential-manager configure

Uninstall

git-credential-manager unconfigure
sudo dpkg -r gcm
