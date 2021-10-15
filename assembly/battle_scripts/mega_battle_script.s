.text
.thumb
.align 2
/*
mega_battle_scripts.s
	handles mega evolution
*/

.include "../asm_defines.s"
.include "../battle_script_macros.s"

.global BattleScript_MegaEvolution
.global BattleScript_MegaWish
.global BattleScript_UltraBurst
.global BattleScript_Dynamax

BattleScript_MegaEvolution:
	setword BATTLE_STRING_LOADER MegaReactingString
	printstring 0x184
	waitmessage DELAY_HALFSECOND

MegaAnimBS:
	playanimation BANK_SCRIPTING ANIM_MEGA_EVOLUTION 0x0
	reloadhealthbar BANK_SCRIPTING
	setword BATTLE_STRING_LOADER MegaEvolutionCompleteString
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_MegaWish:
	setword BATTLE_STRING_LOADER FerventWishString
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	goto MegaAnimBS

BattleScript_UltraBurst:
	setword BATTLE_STRING_LOADER UltraBurstGlowingString
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	playanimation BANK_SCRIPTING ANIM_ULTRA_BURST 0x0
	reloadhealthbar BANK_SCRIPTING
	setword BATTLE_STRING_LOADER UltraBurstCompleteString
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_Dynamax:
	call BS_FLUSH_MESSAGE_BOX
	callasm UpdateHPForDynamax
	playanimation BANK_SCRIPTING ANIM_CALL_BACK_POKEMON
	waitanimation
	pause DELAY_1SECOND
	pause DELAY_HALFSECOND
	returntoball BANK_SCRIPTING
	call BattleScript_TryRevertCramorant

BattleScript_Dynamax_Rejoin:
	waitstateatk
	callasm TryDoDynamaxTrainerSlide
	callasm SetAndTransferDontRemoveTransformSpecies
	callasm BackupScriptingBankMoveSelectionCursor @;Prevents the move selection cursor from being reset by the switch-in anim
	switchinanim BANK_SCRIPTING 0x1 @;Play the switch-in animation
	waitanimation
	callasm RestoreScriptingBankMoveSelectionCursor
	callasm ClearAndTransferDontRemoveTransformSpecies
	playanimation BANK_SCRIPTING ANIM_DYNAMAX_START 0x0
	orword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	graphicalhpupdate BANK_SCRIPTING
	datahpupdate BANK_SCRIPTING
	bicword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	setword BATTLE_STRING_LOADER gText_MonDynamaxed
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_TryRevertCramorant:
	formchange BANK_SCRIPTING SPECIES_CRAMORANT_GULPING SPECIES_CRAMORANT TRUE TRUE FALSE BattleScript_TryRevertGorgingCramorant
BattleScript_TryRevertGorgingCramorant:
	formchange BANK_SCRIPTING SPECIES_CRAMORANT_GORGING SPECIES_CRAMORANT TRUE TRUE FALSE BattleScript_Dynamax_Rejoin
	goto BattleScript_Dynamax_Rejoin

.align 2
@;FD 00's FD 16 is reacting\nto FD 04's FD 01!
MegaReactingString: .byte 0x03, 0x0B, 0xFD, 0x16, 0x03, 0x79, 0xFE, 0x00, 0xFD, 0x39, 0x03, 0x0B, 0xFD, 0x01, 0x0A, 0xAB, 0x03, 0xB7, 0x0F, 0x54, 0xAB, 0xFF
MegaEvolutionCompleteString: .byte 0xFD, 0x13, 0xC7, 0xD9, 0xDB, 0xD5, 0x07, 0x4A, 0x05, 0x3C, 0xFE, 0x02, 0x4B, 0xC7, 0xD9, 0xDB, 0xD5, 0xFD, 0x00, 0x08, 0x9E, 0xAB, 0xFF
FerventWishString: .byte 0xFD, 0x39, 0x03, 0x0B, 0x0F, 0xC4, 0x0D, 0x63, 0xFE, 0x0F, 0x21, 0x07, 0x5D, 0x02, 0xCF, 0x03, 0x04, 0xFD, 0x00, 0xAB, 0xFF
UltraBurstGlowingString: .byte 0xFD, 0x13, 0x10, 0x70, 0x0F, 0xE6, 0x01, 0x69, 0x03, 0xA5, 0x0A, 0xD8, 0x04, 0xAA, 0xAB, 0xFF
UltraBurstCompleteString: .byte 0xFD, 0x13, 0x0D, 0x20, 0x04, 0xC5, 0x07, 0x6F, 0x05, 0x96, 0x01, 0x69, 0x03, 0xA5, 0xFE, 0x05, 0x7E, 0x03, 0x0A, 0x08, 0x9E, 0x0A, 0xD8, 0x02, 0xD3, 0x03, 0x0B, 0x09, 0xD2, 0x08, 0x92, 0xAB, 0xFF
