#pragma once
#include <string>

#include "Structures/List.h"

namespace AccountDatabase {

	typedef uint32_t ID;

	class Model
	{
	public:
		virtual ~Model() = default;
		Model() = default;
		Model(ID _id)
			: m_ID(_id)
		{
		}

		virtual void FromString(ID _id, const mtk::List<std::string_view>& _data) = 0;
		virtual void FromString(ID _id, const mtk::List<std::string>& _data) = 0;
		virtual void FromString(ID _id, const mtk::List<const char*>& _data) = 0;

		const ID& GetID() const { return m_ID; }

		virtual std::string ToString() const = 0;

	protected:
		ID m_ID = 0;
	};
}
