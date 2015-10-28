#include <iostream>
#include "Gamepad.h"

using namespace std;

void main()
{
	// create gamepad instance (controller no. 1)
	Gamepad MyGamepad = Gamepad(1);

	while (true)
	{
		MyGamepad.Update(); // Update the gamepad

		if (MyGamepad.GetButtonPressed(0))
			cout << "A";

		if (MyGamepad.GetButtonDown(2))
			cout << "X";

		if (MyGamepad.GetButtonDown(3))
			cout << "Y";

			// Update the gamepad for next frame
			MyGamepad.RefreshState();
	}
}