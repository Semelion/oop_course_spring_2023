#rm -rf bin/
rm -rf build/

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/home/semelion/vcpkg/scripts/buildsystems/vcpkg.cmake
else
	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/Users/user2023/vcpkg/scripts/buildsystems/vcpkg.cmake
fi

cmake --build build --config Release

cmake --install ./build  --prefix ./course_work_cpnsole
