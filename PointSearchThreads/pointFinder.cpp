void pointFinder::getUserInput()
{
	int x, y;
	
	cout << "\nThis program finds the point closest to a user made point" <<
		"on a 1000x1000 grid." << endl;

	cout << "\nEnter the X coordinate of your point: ";
	cin >> x;
	cout << "Enter the Y coordinate of your point: ";
	cin >> y;

	refPoint.x = x;
	refPoint.y = y;
}