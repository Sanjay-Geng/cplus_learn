cmake:
	mkdir -p build
	cd build; cmake .. ; $(MAKE)

clean:
	rm -rf build
	rm -rf bin
