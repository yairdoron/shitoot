#pragma once
#pragma once

#include "BorderDrawer.h"

#include "SingleBorderDrawer.h"


enum class BorderType
{
	Single, Double, None
};

class SimpleBorderFactory
{

	private:
		SimpleBorderFactory() = default;


	public:

	const BorderDrawer& getSingle()
	{
		return _single;
	}

	const BorderDrawer& getBorderDrawer(BorderType border)
	{				
	
		switch (border)
		{
			case BorderType::Single:
				return _single;
			case BorderType::Double:
				return _single;
			case BorderType::None:
				return _single;
			default:
				throw "Invalid border type";
		}
	}


	static SimpleBorderFactory& instance()
	{
		static SimpleBorderFactory instance;
		return instance;
	}

		const SingleBorderDrawer _single;			// we make him alive!
	
};
