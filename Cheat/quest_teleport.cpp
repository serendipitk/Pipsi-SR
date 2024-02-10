#include "quest_teleport.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "inputs.h"

#include "utils.h"

#include "imgui_internal.h"

namespace QuestTeleport
{
	void* GetTargetPosHandler(void* _this, void* _res)
	{
		void* lpResult = CALL_ORIGIN(GetTargetPosHandler, _this, _res);

		if (!lpResult || !bQuestTeleport)
			return lpResult;

		if (Inputs::GetState(dwQuestTeleportKey, INPUT_TYPE_HOLD))
			Engine::PlayerTeleport(lpResult);

		return lpResult;
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Quest Teleport");

		ImGui::Checkbox("Enable", &bQuestTeleport);

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(RPG::Client::AdventureWaypointTarget::GetTargetPos, GetTargetPosHandler);
	}
}