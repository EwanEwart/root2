# ROOT access: replace name
$ xhost +si:localuser:<name>

# github automation
git config --global credential.helper manager

## GCM - git credential manager
### Debian package
#### Install GCM

*Download* the latest .deb package,
and *run* the following:

sudo dpkg -i <path-to-package>
git-credential-manager configure

### Uninstall GCM

git-credential-manager unconfigure
sudo dpkg -r gcm

### github automation gcm-post-installation
git config --global credential.credentialStore cache

