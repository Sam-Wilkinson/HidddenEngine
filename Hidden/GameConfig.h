#pragma once


namespace Hidden
{
	struct WindowSize
	{
		int Width;
		int Height;
	};

	struct GameConfig
	{
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		enum class gameModes 
		{
			singlePlayer,
			coop,
			versus
		};

		static WindowSize window;

	};

}
