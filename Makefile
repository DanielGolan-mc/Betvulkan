#   This Source Code Form is subject to the terms of the Mozilla Public
#   License, v. 2.0. If a copy of the MPL was not distributed with this
#   file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
#   Copright (C) 2023 SnowyFox

CFLAGS = -std=c++17
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
FILENAME = .output

compile: src/main.cpp
	g++ $(CFLAGS) -o $(FILENAME) src/main.cpp $(LDFLAGS)

.PHONY: test clean

test: compile
	./$(FILENAME)

clean:
	rm -f $(FILENAME)
