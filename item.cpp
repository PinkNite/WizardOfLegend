#include "stdafx.h"
#include "item.h"



ITEM::ITEM()
	:_x(0), _y(0), _alpha(255), _isDrop(0)
{
}

ITEM::~ITEM()
{
}

HRESULT ITEM::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("items", "resource/item/ItemIcons.bmp", 624, 624, 16, 16, true, RGB(255, 0, 255)));

	//_pImage = IMAGEMANAGER->addFrameImage("items", "resourse/image/ItemIcons.bmp", 624, 624, 16, 16, true, RGB(255, 0, 255));
	_x = x;
	_y = y;

	for (int i = 0; i < 256; i++)
	{
		TAGITEM item;
		item.frameX = i % 16;
		item.frameY = i / 16;
		item.name = " ";
		item.info = " ";
		item.type = DEFENSE;
		item.costA = 0;
		item.costB = 0;
		item.pool = 0;
		item.isDrop = false;//¶³¾îÁ³³Ä  Æ®·ç¸é ¶³¾îÁü
		switch (i)
		{
		case 0:
			item.name = "Amulet of Sundering";
			item.info = "Increases all damage dealt!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 1:
			item.name = "Ifrit's Matchstick";
			item.info = "Increases fire damage!";
			item.type = OFFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;

			break;
		case 2:
			item.name = "Rudra's Pinwheel";
			item.info = "Increases air damage!";
			item.type = OFFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;

			break;
		case 3:
			item.name = "Gaia's Shovel";
			item.info = "Increases earth damage!";
			item.type = OFFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 4:
			item.name = "Battery of Taranis";
			item.info = "Increases lightning damage!";
			item.type = OFFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 5:
			item.name = "Shiva's Water Bottle";
			item.info = "Increases water damage!";
			item.type = OFFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;

		case 6:
			item.name = "Phoenix Talon";
			item.info = "Adds a chance to burn foes!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 7:
			item.name = "Nerite Shell";
			item.info = "Adds a chance to slow foes!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 8:
			item.name = "Noxious Dappercap";
			item.info = "Adds a chance to poison foes!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 9:
			item.name = "Tesla Coil";
			item.info = "Adds a chance to shock foes!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 10:
			item.name = "Permafrost Cube";
			item.info = "a chance to freeze foes!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 11:
			item.name = "Analytical Monocle";
			item.info = "Increases critical hit chance!";
			item.type = OFFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 12:
			item.name = "Agni's Sparkler";
			item.info = "Increases ferocity of your burn status effects!";
			item.type = OFFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 13:
			item.name = "Idealist's Mirror";
			item.info = "All arcana are empowered when at full health!";
			item.type = OFFENSE;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 14:
			item.name = "Berserker's Helm";
			item.info = "Damage increased while at low health!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 15:
			item.name = "Royal Flush";
			item.info = "Equipping arcana of the same element increases damage!";
			item.type = OFFENSE;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 16:
			item.name = "Captain's Ring";
			item.info = "Equipping arcana of differing elements increases damage!";
			item.type = OFFENSE;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 17:
			item.name = "Dagger of Midas";
			item.info = "Increases damage based on how much gold you currently have!";
			item.type = OFFENSE;
			item.costA = 25;
			item.costB = 125;
			item.pool = 5;
			break;

		case 18:
			item.name = "Friendship Bracelet";
			item.info = "Increase damage and movement speed when you're with a true friend!";
			item.type = OFFENSE;
			item.costA = 0;
			item.costB = 0;
			item.pool = 1;
			break;
		case 19:
			item.name = "Autograph Pad";
			item.info = "Damage and movement speed is increased while signature arcana is charged!";
			item.type = OFFENSE;
			item.costA = 25;
			item.costB = 125;
			item.pool = 5;
			break;
		case 20:
			item.name = "Neve's Ruby";
			item.info = "Holding seven fire arcana increases damage!All arcana burns foes!";
			item.type = OFFENSE;
			item.costA = 30;
			item.costB = 250;
			item.pool = 5;
			break;
		case 21:
			item.name = "Neve's Citrine";
			item.info = "Holding seven lightning arcana increases critical chance! All arcana shocks foes!";
			item.type = OFFENSE;
			item.costA = 30;
			item.costB = 0;
			item.pool = 5;
			break;
		case 22:

			item.name = "Stanza of Flames";
			item.info = "All fire arcana cause burning but take double damage from water spells!Second half of the Poem of Fiery Rime.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 23:
			item.name = "Stanza of Frost";
			item.info = "Increases ice damage!First half of the Poem of Fiery Rime.";
			item.type = OFFENSE;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 24:
			item.name = "Sleepy Thunderstone";
			item.info = "Summons an aura that calls down lightning on nearby enemies.";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 25:
			item.name = "Lotus Froststone";
			item.info = "Summons an aura that freezes nearby enemies.";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 26:
			item.name = "Merchant's Cart";
			item.info = "	Increase damage based on number of relics in inventory.";
			item.type = OFFENSE;
			item.costA = 22;
			item.costB = 150;
			item.pool = 4;
			break;
		case 27:
			item.name = "Covert Ops Mask";
			item.info = "After evading an attack, all of your attacks will be critical hits for a short duration!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;

		case 28:
			item.name = "Indra's Copper Pipe";
			item.info = "Increases duration of your shock status effects!";
			item.type = OFFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;

		case 29:
			item.name = "Devi's Bug Spray";
			item.info = "Increases potency of your poison status effects!";
			item.type = OFFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 31:
			item.name = "Dark Katana";
			item.info = "Designed by Artisan Mathosse Feadur, this relic triples the critical hit chance for all melee arcana!";
			item.type = OFFENSE;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
		case 32:

			item.name = "Cobalt Firestone";
			item.info = "Summons an aura that damages nearby enemies!";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 33:
			item.name = "Special Snowflake";
			item.info = "Defeated enemies have a chance to explode and freeze nearby enemies!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 34:
			item.name = "Cartographer's Quill";
			item.info = "Increases damage based on how much of the map you have revealed!";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 35:
			item.name = "Berserker's Axe";
			item.info = "Increases damage dealt for a short while after taking damage!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 36:
			item.name = "Fortune Cookie";
			item.info = "Randomly empowers an arcana at the beginning of each stage!";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;

		case 38:
			item.name = "Hunter's Stiletto";
			item.info = "Increase damage against foes that are inflicted with a status ailment.";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 40:
			item.name = "Whimsical Explodium";
			item.info = "Adds a chance that enemies will explode when defeated!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 125;
			item.pool = 5;
			break;
		case 41:
			item.name = "Auditor's Talisman";
			item.info = "Increases critical hit chance at low health!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 42:

			item.name = "Dice of the Nemesis";
			item.info = "Adds a small chance of dealing massive damage with your critical hits!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 43:
			item.name = "Ebon Wolf's Cloak";
			item.info = "Increases fire and lightning arcana damage, but receive more damage from water and earth attacks!";
			item.type = OFFENSE;
			item.costA = 19;
			item.costB = 175;
			item.pool = 3;
			break;
		case 44:
			item.name = "Ancient Fountain Pen";
			item.info = "Your charged signature arcana deals more damage every time you use it!";
			item.type = OFFENSE;
			item.costA = 22;
			item.costB = 150;
			item.pool = 4;
			break;
		case 45:
			item.name = "Singing Bowl";
			item.info = "Not using arcana for a short period of time causes your next spell to be a critical hit!";
			item.type = OFFENSE;
			item.costA = 19;
			item.costB = 175;
			item.pool = 3;
			break;
		case 48:
			item.name = "Assassin's Blade";
			item.info = "Increases critical hit damage!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 49:
			item.name = "Sinister Ledger";
			item.info = "Designed by Artisan Steven Wu, this relic increases all damage for every enemy defeated, but loses effectiveness when taking damage.";
			item.type = OFFENSE;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 50:
			item.name = "Secret Wild Card";
			item.info = "Your signature will take longer to charge, but can now be used twice on a single charge!";
			item.type = OFFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 51:
			item.name = "Sidewinder's Badge";
			item.info = "All melee basic arcana have a secondary hit that deals reduced damage!";
			item.type = OFFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 53:

			item.name = "Tapping Gloves";
			item.info = "Following up a basic arcana with another arcana increases its critical hit chance!";
			item.type = OFFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 54:
			item.name = "Wanderer's Mechanism";
			item.info = "Increases the damage of your signature arcana! Core of the Perfect Time Crystal.";
			item.type = OFFENSE;
			item.costA = 19;
			item.costB = 175;
			item.pool = 5;
			break;
		case 55:
			item.name = "Whimsical Explodium";
			item.info = "Adds a chance that enemies will explode when defeated!";
			item.type = OFFENSE;
			item.costA = 26;
			item.costB = 125;
			item.pool = 5;
		case 64:
			item.name = "Giant's Heart";
			item.info = "Increases max health!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 65:
			item.name = "Euphie's Shawl";
			item.info = "Increases armor!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 66:

			item.name = "Armor of Resolve";
			item.info = "Increases armor while at low health!";
			item.type = DEFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 67:
			item.name = "Antiquated Tabi";
			item.info = "Adds a small chance to evade attacks!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 68:
			item.name = "Mercury's Sandals";
			item.info = "Increases movement speed!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 69:
			item.name = "Hummingbird Feather";
			item.info = "Briefly hover over pits!";
			item.type = DEFENSE;
			item.costA = 22;
			item.costB = 150;
			item.pool = 4;
			break;
		case 70:
			item.name = "Leemo's Leaf";
			item.info = "Evade all attacks while dashing!";
			item.type = DEFENSE;
			item.costA = 24;
			item.costB = 200;
			item.pool = 4;
			break;
		case 72:
			item.name = "Lei's Drum";
			item.info = "Release a burst of lightning when taking damage!";
			item.type = DEFENSE;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 73:

			item.name = "Super Sunscreen";
			item.info = "Prevents burn status effect!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 75:
			item.name = "Gummy Vitamins";
			item.info = "Prevents poison status effect!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 77:

			item.name = "Fuzzy Handwarmers";
			item.info = "Prevents freeze status effect!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 80:
			item.name = "Limited Edition Robe";
			item.info = "Reduces damage taken to a maximum of 10 % of max health!";
			item.type = DEFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 81:
			item.name = "Jewelry Box";
			item.info = "Picking up chaos gems heals for a small amount.Excludes gems collected from Council members.";
			item.type = DEFENSE;
			item.costA = 20;
			item.costB = 200;
			item.pool = 3;
			break;
		case 82:
			item.name = "Neve's Quartz";
			item.info = "Holding seven air arcana increases movement speed and evasion. All arcana slows foes!";
			item.type = DEFENSE;
			item.costA = 30;
			item.costB = 0;
			item.pool = 5;
			break;
		case 83:
			item.name = "Neve's Emerald";
			item.info = "Holding seven earth arcana increase health and armor and lowers stun and knockback!";
			item.type = DEFENSE;
			item.costA = 30;
			item.costB = 0;
			item.pool = 5;
			break;
		case 84:
			item.name = "Thesis on Defense";
			item.info = "Every point of damage taken adds a page to this thesis.Every 200 pages reduces all damage taken by 1. (Maximum 600 pages)";
			item.type = DEFENSE;
			item.costA = 17;
			item.costB = 125;
			item.pool = 3;
			break;
		case 86:
			item.name = "Cushioned Flip - flops";
			item.info = "Damage taken is expended from your signature meter while you have sufficient charge to shield the attack!";
			item.type = DEFENSE;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 87:
			item.name = "Mirror Shield";
			item.info = "Summons a shield that reflects one projectile!Shield breaks after reflect and respawns on a timer.";
			item.type = DEFENSE;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 89:

			item.name = "Takeout Box";
			item.info = "When healed for more than your maximum health, gain a shield equal to half of the excess heal amount";
			item.type = DEFENSE;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 90:
			item.name = "Pazu's Favorite Hat";
			item.info = "Revive with low health when defeated! Hat can also create health orbs when dropped. This relic is destroyed on use.";
			item.type = DEFENSE;
			item.costA = 22;
			item.costB = 250;
			item.pool = 3;
			break;
		case 92:
			item.name = "Tea of Mercy";
			item.info = "All heals increase your max health up to a certain limit!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;

		case 94:

			item.name = "Raspberry Cookie Box";
			item.info = "Health orbs drop more frequently!";
			item.type = DEFENSE;
			item.costA = 11;
			item.costB = 175;
			item.pool = 1;
			break;

		case 95:

			item.name = "Vampire's Eyeglasses";
			item.info = "Regenerate health every time you land a critical hit!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 96:
			item.name = "Regenerative Inkwell";
			item.info = "Using a fully charged signature arcana heals you instead of producing a signature spell!";
			item.type = DEFENSE;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 97:
			item.name = "Scissors of Vitality";
			item.info = "Sacrifice all standard arcana in your hand to revive from defeat!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 250;
			item.pool = 4;
			break;

		case 98:
			item.name = "Pathfinder's Knapsack";
			item.info = "On clearing the floor, receive a heal based on the map reveal percentage.";
			item.type = DEFENSE;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 99:
			item.name = "Tortoise Shield";
			item.info = "Increase armor but decrease damage!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 100:

			item.name = "Reactive Vinemail";
			item.info = "Releases a grove of rooting vines when taking damage!";
			item.type = DEFENSE;
			item.costA = 19;
			item.costB = 175;
			item.pool = 3;
			break;

		case 101:

			item.name = "Deafening Cymbals";
			item.info = "Destroys all projectiles in the area when hit by a projectile!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 102:
			item.name = "Elven Ears";
			item.info = "Remaining motionless for a short time causes you to disappear from sight!";
			item.type = DEFENSE;
			item.costA = 27;
			item.costB = 125;
			item.pool = 5;
			break;
		case 103:
			item.name = "Greased Boots";
			item.info = "Lowers the cooldown of your dash arcana and adds an extra use!";
			item.type = DEFENSE;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 104:
			item.name = "Charming Teddy Bear";
			item.info = "Adds a chance to charm enemies when taking damage!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 105:
			item.name = "Heavy Travel Jacket";
			item.info = "Increases armor for each relic held!";
			item.type = DEFENSE;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;

		case 106:
			item.name = "Bracers of the Beast";
			item.info = "Pressing forward into an attack immediately before impact allows you to guard the attack!";
			item.type = DEFENSE;
			item.costA = 22;
			item.costB = 150;
			item.pool = 4;
			break;

		case 107:

			item.name = "Calvin's Sandy Shoes";
			item.info = "Adds a chance to evade while at low health!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 108:
			item.name = "Spell Thief's Socks";
			item.info = "Increase movement speed everytime an arcana is used! Speed is increased for each arcana on cooldown!";
			item.type = DEFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 109:

			item.name = "Calcifying Bonemail";
			item.info = "Increases armor for a short duration after taking damage!";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 110:
			item.name = "Demi's Teapot";
			item.info = "Increases the duration of buff arcana!";
			item.type = DEFENSE;
			item.costA = 27;
			item.costB = 175;
			item.pool = 0;
			break;
		case 112:

			item.name = "Resolute Svalinn";
			item.info = "Increases resistance to fire based attacks!";
			item.type = DEFENSE;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 113:
			item.name = "Three Gorges Bulwark";
			item.info = "Increases resistance to water based attacks!";
			item.type = DEFENSE;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 114:
			item.name = "Ring of Recycling";
			item.info = "Gain a shield every time a charged signature is not activated and times out.";
			item.type = DEFENSE;
			item.costA = 24;
			item.costB = 200;
			item.pool = 4;
			break;
		case 116:
			item.name = "Tracking Suit";
			item.info = "Arcana of matching elements increases resistance to that element!Requires two or more arcana of the same element.";
			item.type = DEFENSE;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 117:

			item.name = "Kali's Flower Diadem";
			item.info = "When taking damage that would defeat you, gain full signature charge and briefly become immune to defeat!";
			item.type = DEFENSE;
			item.costA = 22;
			item.costB = 250;
			item.pool = 3;
			break;
		case 129:

			item.name = "Roxel's Pendulum";
			item.info = "Reduces all cooldowns!";
			item.type = MISC;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 130:

			item.name = "Tozy's Pocket Watch";
			item.info = "Designed by Artisan Curt 'Tozy' Toczydlowski, this relic reduces cooldowns but also reduces signature charge rate!";
			item.type = MISC;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 131:

			item.name = "Destructive Abacus";
			item.info = "Defeating foes lowers active cooldowns!";
			item.type = MISC;
			item.costA = 20;
			item.costB = 200;
			item.pool = 3;
			break;
		case 133:

			item.name = "Igniting Sprite Vesa";
			item.info = "Summons a sprite that burns enemies!Only one sprite can be active at any time.";
			item.type = MISC;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 134:

			item.name = "Blasting Sprite Aura";
			item.info = "Summons a sprite that slows enemies!Only one sprite can be active at any time.";
			item.type = MISC;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 135:

			item.name = "Plaguing Sprite Dria";
			item.info = "Summons a sprite that poisons enemies!Only one sprite can be active at any time.";
			item.type = MISC;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 136:
			item.name = "Sparking Sprite Etra";
			item.info = "Summons a sprite that shocks enemies!Only one sprite can be active at any time.";
			item.type = MISC;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 137:

			item.name = "Freezing Sprite Naya";
			item.info = "Summons a sprite that freezes enemies!Only one sprite can be active at any time.";
			item.type = MISC;
			item.costA = 22;
			item.costB = 125;
			item.pool = 1;
			break;
		case 138:
			item.name = "Surefire Rocket";
			item.info = "Signature charge no longer decays while building up!";
			item.type = MISC;
			item.costA = 11;
			item.costB = 175;
			item.pool = 1;
			break;

		case 139:

			item.name = "Infinity Marble";
			item.info = "Signature charge stays active until used!";
			item.type = MISC;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 140:
			item.name = "Hyperbolic Train";
			item.info = "Signature charges faster at low health!";
			item.type = MISC;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 141:
			item.name = "Albert's Formula";
			item.info = "Receive signature charge when healed!";
			item.type = MISC;
			item.costA = 17;
			item.costB = 125;
			item.pool = 3;
			break;

		case 142:
			item.name = "Grimoire of Ruin";
			item.info = "Increases the damage of summoned agents!";
			item.type = MISC;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 143:

			item.name = "Pop - up Primer";
			item.info = "Increases the number of summoned agents, but lowers their health!";
			item.type = MISC;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 144:
			item.name = "Yuna's Storybook";
			item.info = "Increases the duration of summoned agents!";
			item.type = MISC;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 147:
			item.name = "Combo Gloves";
			item.info = "Basic arcana have an extra combo!";
			item.type = MISC;
			item.costA = 10;
			item.costB = 150;
			item.pool = 1;
			break;
		case 148:
			item.name = "Evening Gloves";
			item.info = "Basic arcana chains are completed automatically!";
			item.type = MISC;
			item.costA = 16;
			item.costB = 100;
			item.pool = 3;
			break;

		case 149:
			item.name = "Ring of Reserves";
			item.info = "Adds more uses to all multi - use arcana!";
			item.type = MISC;
			item.costA = 11;
			item.costB = 175;
			item.pool = 1;
			break;
		case 150:
			item.name = "Neve's Sapphire";
			item.info = "Holding seven water arcana reduces all cooldowns and increases healing!";
			item.type = MISC;
			item.costA = 30;
			item.costB = 0;
			item.pool = 5;
			break;
		case 151:
			item.name = "Spice Rack";
			item.info = "Using an arcana of a different element reduces the cooldown of the previously used arcana.";
			item.type = MISC;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 152:
			item.name = "Relic Rewards Card";
			item.info = "All gold costs for relics are discounted!";
			item.type = MISC;
			item.costA = 12;
			item.costB = 100;
			item.pool = 2;
			break;
		case 153:
			item.name = "Arcana Rewards Card";
			item.info = "All gold costs for arcana are discounted!";
			item.type = MISC;
			item.costA = 12;
			item.costB = 100;
			item.pool = 2;
			break;

		case 154:
			item.name = "Nocturnal Sundial";
			item.info = "Adds a chance that an arcana will not go on cooldown after use!";
			item.type = MISC;
			item.costA = 23;
			item.costB = 175;
			item.pool = 4;
			break;
		case 155:
			item.name = "Phyyrnx's Hourglass";
			item.info = "Designed by Artisan PerdyDarnSavvy, this relic activates when taking damage at low health and briefly removes the cooldown on all arcana!";
			item.type = MISC;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;
		case 156:
			item.name = "Equestricap";
			item.info = "Designed by Artisan Tacobowl8, this relic allows you to look quite dashing as you gallop to max speed with ease!";
			item.type = MISC;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 157:

			item.name = "Boots of Frenzy";
			item.info = "Defeating enemies grants a chance to temporarily add unlimited charges to your movement arcana!";
			item.type = MISC;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 158:

			item.name = "Absorption Coil";
			item.info = "A percentage of damage taken charges your signature arcana!";
			item.type = MISC;
			item.costA = 26;
			item.costB = 150;
			item.pool = 5;
			break;
		case 159:

			item.name = "Chaos Scanner";
			item.info = "Reveals health bars for all enemies in the Chaos Trials!";
			item.type = MISC;
			item.costA = 24;
			item.costB = 100;
			item.pool = 5;
			break;
		case 160:

			item.name = "Sano's Headband";
			item.info = "You can no longer be interrupted while casting an arcana!";
			item.type = MISC;
			item.costA = 21;
			item.costB = 125;
			item.pool = 4;
			break;
		case 162:

			item.name = "Wallet of Vigor";
			item.info = "Enables you to purchase items with health when you don't have sufficient gold.";
			item.type = MISC;
			item.costA = 20;
			item.costB = 100;
			item.pool = 4;
			break;
		case 163:

			item.name = "Raffle Ticket";
			item.info = "Adds a chance that an item purchased in the Chaos Trials will be free of charge.";
			item.type = MISC;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 164:

			item.name = "Tears of Midas";
			item.info = "Gain gold when taking damage!";
			item.type = MISC;
			item.costA = 25;
			item.costB = 125;
			item.pool = 5;
			break;
		case 165:

			item.name = "Supply Crate";
			item.info = "The relic and arcana stores will instantly restock after purchase!Health potions are of short supply and will not be restocked.";
			item.type = MISC;
			item.costA = 22;
			item.costB = 50;
			item.pool = 5;
			break;
		case 166:

			item.name = "C - 99 Piggy Bank";
			item.info = "Gets heavier as you progress through the trials.Drop from inventory to open.";
			item.type = MISC;
			item.costA = 18;
			item.costB = 0;
			item.pool = 3;
			break;
		case 167:

			item.name = "Flak Gauntlet";
			item.info = "Allows you to destroy enemy projectiles with melee basic arcana!";
			item.type = MISC;
			item.costA = 14;
			item.costB = 150;
			item.pool = 2;
			break;
		case 168:

			item.name = "Journal of Midas";
			item.info = "Gain gold when defeating consecutive enemies without taking damage!";
			item.type = MISC;
			item.costA = 21;
			item.costB = 125;
			item.pool = 4;
			break;
		case 169:

			item.name = "Reinforced Bracers";
			item.info = "Your projectiles destroy any other projectiles they strike!";
			item.type = MISC;
			item.costA = 28;
			item.costB = 200;
			item.pool = 5;
			break;
		case 170:

			item.name = "Elemental Pointes";
			item.info = "Using a dash arcana immediately after another arcana lowers cooldowns for all arcana of the same element as your dash!";
			item.type = MISC;
			item.costA = 22;
			item.costB = 150;
			item.pool = 4;
			break;
		case 171:

			item.name = "Bladed Buckler";
			item.info = "Destroying an enemy projectile grants signature charge energy!";
			item.type = MISC;
			item.costA = 27;
			item.costB = 175;
			item.pool = 5;
			break;
		case 172:

			item.name = "Conqueror's Helmet";
			item.info = "All Knights and Lancers have their spells limited! Only one Conqueror item can be in effect at a time.";
			item.type = MISC;
			item.costA = 29;
			item.costB = 0;
			item.pool = 5;
			break;
		case 173:

			item.name = "Conqueror's Belt";
			item.info = "All Rogues and Archers have their spells limited! Only one Conqueror item can be in effect at a time.";
			item.type = MISC;
			item.costA = 29;
			item.costB = 0;
			item.pool = 5;
			break;
		case 174:

			item.name = "Conqueror's Cloak";
			item.info = "All Mages and Summoners have their spells limited! Only one Conqueror item can be in effect at a time.";
			item.type = MISC;
			item.costA = 29;
			item.costB = 0;
			item.pool = 5;
			break;
		case 186:

			item.name = "Glove of Midas";
			item.info = "Increase gold gain for all wizards!Multiple gloves do not stack.";
			item.type = MISC;
			item.costA = 10;
			item.costB = 125;
			item.pool = 1;
			break;
		case 188:

			item.name = "Pathfinder's Map";
			item.info = "Reveals the layout and main points of interest of the Chaos Trials!";
			item.type = MISC;
			item.costA = 18;
			item.costB = 150;
			item.pool = 3;
			break;
		case 189:

			item.name = "Unicorn Tail";
			item.info = "Rainbows!";
			item.type = MISC;
			item.costA = 24;
			item.costB = 100;
			item.pool = 5;
			break;
		case 190:

			item.name = "Insignia of Legend";
			item.info = "A crest presented only to those who have cleared the Chaos Trials!";
			item.type = MISC;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 192:

			item.name = "Double Trouble";
			item.info = "Deal double damage but receive double damage!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 193:

			item.name = "Double Toil";
			item.info = "Reduces cooldowns by half but receive double damage!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 194:

			item.name = "Vampire's Fangs";
			item.info = "Defeating enemies regenerates health but max health is reduced!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 195:

			item.name = "Horned Halo";
			item.info = "Revive with low health when defeated but consumes half of current health when picked up!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 196:

			item.name = "Glass Cannon";
			item.info = "Damage increased but max health is reduced!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 197:

			item.name = "Flashy Boots";
			item.info = "Allows you to triple dash but lowers movement speed!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 198:

			item.name = "Armor of Greed";
			item.info = "Grants a significant boost in armor!Every hit taken reduces gold count.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 199:

			item.name = "Anchor of Burden";
			item.info = "Damage and stuns are increased but movement speed is reduced for each cursed relic owned!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 200:

			item.name = "Paronomasicon";
			item.info = "Your attacks on council members are more pun - ishing!Enemy attacks pack an extra pun - ch.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 201:
			item.name = "Volatile Gemstone";
			item.info = "Signature charge rate and decay are increased dramatically but charged signature damage is reduced!Shell of the Perfect Time Crystal.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;

		case 202:

			item.name = "Overpriced Insurance";
			item.info = "Expend all gold at the start of each stage and heal for a fraction of the expended amount.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 203:

			item.name = "Crimson Clover";
			item.info = "Critical hit chance is increased for you and all enemies!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 204:

			item.name = "Large Red Button";
			item.info = "Regain full health every time an exit portal is used!Max health is reduced and all healing has no effect.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 206:

			item.name = "Silver Spinning";
			item.info = "Top	Increases the activation speed of arcana but slows movement speed!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 207:

			item.name = "Spiked Emergency Kit";
			item.info = "Regenerate health while at critically low health!Max health is reduced.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 208:

			item.name = "Tortoise Shield";
			item.info = "Increase armor but decrease damage!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 209:
			item.name = "Golden Saber of Envy";
			item.info = "Increases damage but store prices are increased!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 210:

			item.name = "Golden Armor of Envy";
			item.info = "Increases armor but store prices are increased!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 211:

			item.name = "Sharpened Stylus";
			item.info = "Increases damage but signature can no longer be charged!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 212:

			item.name = "Alchemist's Stone";
			item.info = "All Chaos Gems gained during the Chaos Trials are transmuted into gold!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 213:

			item.name = "Nog's Heavenly Boots";
			item.info = "Adds a significant chance to evade attacks but take double damage!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 214:

			item.name = "Ominous Loan Note";
			item.info = "Immediately receive a large sum of gold!All gold gained, with interest, will go toward paying off this debt.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 215:

			item.name = "Tiny Crocodile Heart";
			item.info = "Reduces max health but increases max health for each enemy defeated!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 216:

			item.name = "Broken Plague Flask";
			item.info = "Enemy max health is lowered, but your health is lowered as well!";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 217:

			item.name = "Double Edged Cestus";
			item.info = "Increase basic arcana damage!All other damage decreased.";
			item.type = CURSED;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 218:

			item.name = "Perfect Time Crystal";
			item.info = "Signature damage, charge rate, and decay rate increased!";
			item.type = OFFENSE;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 219:

			item.name = "Poem of Fiery Rime";
			item.info = "Increases fire and ice damage!Adds a chance to freeze and burn foes to fire and ice arcana, respectively.";
			item.type = OFFENSE;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 220:

			item.name = "Critical Placebos";
			item.info = "Makes you believe all your attacks result in critical hits!";
			item.type = DOCTOR;
			item.costA = 0;
			item.costB = 200;
			item.pool = 0;
			break;
		case 221:

			item.name = "Health Care Card";
			item.info = "Receive a discount whenever you purchase potions from the merchant!";
			item.type = DOCTOR;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 222:

			item.name = "Messy Prescription";
			item.info = "Increases healing received from all sources!";
			item.type = DOCTOR;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 223:

			item.name = "Renewing Potion Vial";
			item.info = "Regain a small amount of health when teleporting to the next area!";
			item.type = DOCTOR;
			item.costA = 0;
			item.costB = 0;
			item.pool = 0;
			break;
		case 230:

			item.name = "Phyyrnx's Hourglass";
			item.info = "Designed by Artisan PerdyDarnSavvy, this relic activates when taking damage at low health and briefly removes the cooldown on all arcana!";
			item.type = MISC;
			item.costA = 15;
			item.costB = 175;
			item.pool = 2;
			break;


		}
		_vItem.push_back(item);
		_mItem.insert(make_pair(i, _vItem));

	}
	_num = 60;//¾ø´Â ÀÌ¹ÌÁö




	_pItemWhite = new ITEMWHITE;
	_pItemWhite->init(x-15, y-15);

	return S_OK;
}

void ITEM::release()
{
	OBJECT::setImage(nullptr);
}

void ITEM::update()
{
	_pItemWhite->update();
}

void ITEM::render(HDC hdc)
{
	/*for (int i = 0; i < 256; i++)
	{
		_image->frameRender(getMemDC(), _image->getFrameWidth()*(i%16), _image->getFrameHeight()*(i/16), _mItem.find(i)->second[i].frameX, _mItem.find(i)->second[i].frameY);
		fontRender(getMemDC(), _mItem.find(i)->second[i].info, 600, 600, 30,RGB(50,50,50));
		fontRender(getMemDC(), _mItem.find(i)->second[i].info, 800, 600, 30, RGB(255, 50, 50));
	}*/

	//OBJECT::getImage()->frameRender(hdc, _x, _y, _mItem.find(_num)->second[_num].frameX, _mItem.find(_num)->second[_num].frameY);
	/*fontRender(hdc, _mItem.find(_num)->second[_num].name,"±¼¸²Ã¼", 300, 200, 30, RGB(250, 50, 50));
	fontRender(hdc, _mItem.find(_num)->second[_num].info,"±¼¸²Ã¼", 300, 250, 15, RGB(50, 50, 50));
	sprintf_s(str, "ºí·ç:%d", _mItem.find(_num)->second[_num].costA);
	TextOut(hdc, 300, 350, str, strlen(str));
	sprintf_s(str, "°ñµå:%d", _mItem.find(_num)->second[_num].costB);
	TextOut(hdc, 300, 400, str, strlen(str));
	sprintf_s(str, "¹øÈ£: %d", _num);
	TextOut(hdc, 400, 500, str, strlen(str));*/
	//À§¿¡²¨´Â ´À¸² ¸ÊÀÌ¶ó


	OBJECT::getImage()->alphaFrameRender(hdc, _x, _y, _vItem[_num].frameX, _vItem[_num].frameY, _alpha);
	if (_pItemWhite->getIsAction())
	{
		_pItemWhite->render(hdc);
	}
	//·¼¸¯½ºÂÊ¿¡ ¾µ°Í////////
/*
	char str[200];
	fontRender(hdc, _vItem[_num].name, "±¼¸²Ã¼", 300, 200, 30, RGB(250, 50, 50));
	fontRender(hdc, _vItem[_num].info, "±¼¸²Ã¼", 300, 250, 15, RGB(50, 50, 50));
	sprintf_s(str, "ºí·ç:%d", _vItem[_num].costA);
	TextOut(hdc, 300, 350, str, strlen(str));
	sprintf_s(str, "°ñµå:%d", _vItem[_num].costB);
	TextOut(hdc, 300, 400, str, strlen(str));
	sprintf_s(str, "¹øÈ£: %d", _num);
	TextOut(hdc, 400, 500, str, strlen(str));*/


}

void ITEM::fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color)
{
	char str1[500];
	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);
	sprintf_s(str1, str);
	TextOut(hdc, x, y, str, strlen(str));
	DeleteObject(font);
	DeleteObject(oldfont);

}
