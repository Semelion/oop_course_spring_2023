rm -rf bin/
rm -rf build/

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake
else
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/Users/user2023/vcpkg/scripts/buildsystems/vcpkg.cmake
fi

cmake --build build --config Release
