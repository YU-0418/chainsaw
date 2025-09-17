#!/bin/bash
set -e #出错立即退出

curr=$PWD

BUILD_TYPE="Release"
INSTALL_DIR="$PWD/install"

# 解析参数
while [[ $# -gt 0 ]]; do
  case $1 in
    --build-type)
      BUILD_TYPE="$2"
      shift 2
      ;;
    --install-dir)
      INSTALL_DIR="$2"
      shift 2
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

cd /home/yu/library/chainsaw

# 项目根目录（相对路径或环境变量更灵活）
project_dir="$(dirname "$0")/.."

cd "$project_dir"


cmake -B build -S . -DCMAKE_BUILD_TYPE=$BUILD_TYPE

cmake --build build/ --parallel $(nproc) 

cmake --install build/ --prefix "$INSTALL_DIR"

cd "$curr"

echo "Build ($BUILD_TYPE) and install completed successfully in $INSTALL_DIR!"