### 二. 创建新用户及zsh+vim环境搭建



```sh
### 1.add user

useradd ace

mkdir /home/ace

chown ace:ace /home/ace -R

usermod -d /home/ace ace

passwd ace

### ! 切换用户

su ace

### 2. install zsh git 

sudo apt install git zsh vim neovim

### 3. 配置 ohmyzsh & spacevim

curl -sLf https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh | bash

curl -sLf https://spacevim.org/install.sh | bash
```





### 三. 样式站点选择

> https://github.com/Sathish2905/sample-website-templates



#### filezillza

sftp://domain ,  username, passwd。  快速链接。



### git 操作

```sh
### git 用户配置

git config --global user.name "wang"
git config --global user.email "wang@qq.com"

### clone 仓库
git clone https://wangsongjie666/wangsongjie666.github.io

cd wangsongjie666

## 开发 ，上传文件！
### 完成后

git add .
git commit -m "input your changes"

git push origin master

### .zshrc 进行别名操作 自己动手
```

