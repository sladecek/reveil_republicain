#include "drawing_objects.h"

namespace rr::ui {

// Fragment content (character indices)
const std::array<uint8_t, fragment_content_size> fragment_content = {
    // nr: "0"
    0,

    // "1"
    1,

    // "2"
    2,

    // "3"
    3,

    // "4"
    4,

    // "5"
    5,

    // "6"
    6,

    // "7"
    7,

    // "8"
    8,

    // "9"
    9,

    // colon: ":"
    10,

    // space: " "
    11,

    // bell: "🔔"
    63,

    // run: "run"
    45, 48, 41,

    // stop: "stop"
    46, 47, 42, 43,

    // alarm: "alarm"
    29, 39, 29, 45, 40,

    // hour: "hour"
    36, 42, 48, 45,

    // minute: "minute"
    40, 37, 41, 48, 47, 33,

    // set: "set"
    46, 33, 47,

    // day: "day"
    32, 29, 51,

    // month: "month"
    40, 42, 41, 47, 36,

    // year: "year"
    51, 33, 29, 45,

    // annee: "Année "
    14, 41, 41, 56, 33, 11,

    // decade: " Décade "
    11, 16, 56, 31, 29, 32, 33, 11,

    // jourdu: "Jour du "
    19, 42, 48, 45, 11, 32, 48, 11,

    // jourepagomene: "Jour épagomène"
    19, 42, 48, 45, 11, 56, 43, 29, 35, 42, 40, 55, 41, 33,

    // on_off: "on"
    42, 41,

    // "off"
    42, 34, 34,

    // months: "Vendémiaire"
    28, 33, 41, 32, 56, 40, 37, 29, 37, 45, 33,

    // "Brumaire"
    15, 45, 48, 40, 29, 37, 45, 33,

    // "Frimaire"
    17, 45, 37, 40, 29, 37, 45, 33,

    // "Nivôse"
    21, 37, 49, 60, 46, 33,

    // "Pluviôse"
    23, 39, 48, 49, 37, 60, 46, 33,

    // "Ventôse"
    28, 33, 41, 47, 60, 46, 33,

    // "Germinal"
    18, 33, 45, 40, 37, 41, 29, 39,

    // "Floréal"
    17, 39, 42, 45, 56, 29, 39,

    // "Prairial"
    23, 45, 29, 37, 45, 37, 29, 39,

    // "Messidor"
    20, 33, 46, 46, 37, 32, 42, 45,

    // "Thermidor"
    27, 36, 33, 45, 40, 37, 32, 42, 45,

    // "Fructidor"
    17, 45, 48, 31, 47, 37, 32, 42, 45,

    // days: "Primidi"
    23, 45, 37, 40, 37, 32, 37,

    // "Duodi"
    16, 48, 42, 32, 37,

    // "Tridi"
    27, 45, 37, 32, 37,

    // "Quartidi"
    24, 48, 29, 45, 47, 37, 32, 37,

    // "Quintidi"
    24, 48, 37, 41, 47, 37, 32, 37,

    // "Sextidi"
    26, 33, 50, 47, 37, 32, 37,

    // "Septidi"
    26, 33, 43, 47, 37, 32, 37,

    // "Octidi"
    22, 31, 47, 37, 32, 37,

    // "Nonidi"
    21, 42, 41, 37, 32, 37,

    // "Décadi"
    16, 56, 31, 29, 32, 37,

    // sansculottides: "Fête de la Vertu"
    17, 57, 47, 33, 11, 32, 33, 11, 39, 29, 11, 28, 33, 45, 47, 48,

    // "Fête du Génie"
    17, 57, 47, 33, 11, 32, 48, 11, 18, 56, 41, 37, 33,

    // "Fête du Travail"
    17, 57, 47, 33, 11, 32, 48, 11, 27, 45, 29, 49, 29, 37, 39,

    // "Fête de l'Opinion"
    17, 57, 47, 33, 11, 32, 33, 11, 39, 12, 22, 43, 37, 41, 37, 42, 41,

    // "Fête des Récompenses"
    17, 57, 47, 33, 11, 32, 33, 46, 11, 25, 56, 31, 42, 40, 43, 33, 41, 46, 33, 46,

    // "Fête de la Révolution"
    17, 57, 47, 33, 11, 32, 33, 11, 39, 29, 11, 25, 56, 49, 42, 39, 48, 47, 37, 42, 41,

    // day_of_year: "raisin"
    45, 29, 37, 46, 37, 41,

    // "safran"
    46, 29, 34, 45, 29, 41,

    // "châtaigne"
    31, 36, 54, 47, 29, 37, 35, 41, 33,

    // "colchique"
    31, 42, 39, 31, 36, 37, 44, 48, 33,

    // "cheval"
    31, 36, 33, 49, 29, 39,

    // "balsamine"
    30, 29, 39, 46, 29, 40, 37, 41, 33,

    // "carotte"
    31, 29, 45, 42, 47, 47, 33,

    // "amarante"
    29, 40, 29, 45, 29, 41, 47, 33,

    // "panais"
    43, 29, 41, 29, 37, 46,

    // "cuve"
    31, 48, 49, 33,

    // "pomme de terre"
    43, 42, 40, 40, 33, 11, 32, 33, 11, 47, 33, 45, 45, 33,

    // "immortelle"
    37, 40, 40, 42, 45, 47, 33, 39, 39, 33,

    // "potiron"
    43, 42, 47, 37, 45, 42, 41,

    // "réséda"
    45, 56, 46, 56, 32, 29,

    // "âne"
    54, 41, 33,

    // "belle de nuit"
    30, 33, 39, 39, 33, 11, 32, 33, 11, 41, 48, 37, 47,

    // "citrouille"
    31, 37, 47, 45, 42, 48, 37, 39, 39, 33,

    // "sarrasin"
    46, 29, 45, 45, 29, 46, 37, 41,

    // "tournesol"
    47, 42, 48, 45, 41, 33, 46, 42, 39,

    // "pressoir"
    43, 45, 33, 46, 46, 42, 37, 45,

    // "chanvre"
    31, 36, 29, 41, 49, 45, 33,

    // "pêche"
    43, 57, 31, 36, 33,

    // "navet"
    41, 29, 49, 33, 47,

    // "amaryllis"
    29, 40, 29, 45, 51, 39, 39, 37, 46,

    // "bœuf"
    30, 62, 48, 34,

    // "aubergine"
    29, 48, 30, 33, 45, 35, 37, 41, 33,

    // "piment"
    43, 37, 40, 33, 41, 47,

    // "tomate"
    47, 42, 40, 29, 47, 33,

    // "orge"
    42, 45, 35, 33,

    // "tonneau"
    47, 42, 41, 41, 33, 29, 48,

    // "pomme"
    43, 42, 40, 40, 33,

    // "céleri"
    31, 56, 39, 33, 45, 37,

    // "poire"
    43, 42, 37, 45, 33,

    // "betterave"
    30, 33, 47, 47, 33, 45, 29, 49, 33,

    // "oie"
    42, 37, 33,

    // "héliotrope"
    36, 56, 39, 37, 42, 47, 45, 42, 43, 33,

    // "figue"
    34, 37, 35, 48, 33,

    // "scorsonère"
    46, 31, 42, 45, 46, 42, 41, 55, 45, 33,

    // "alisier"
    29, 39, 37, 46, 37, 33, 45,

    // "charrue"
    31, 36, 29, 45, 45, 48, 33,

    // "salsifis"
    46, 29, 39, 46, 37, 34, 37, 46,

    // "macre"
    40, 29, 31, 45, 33,

    // "topinambour"
    47, 42, 43, 37, 41, 29, 40, 30, 42, 48, 45,

    // "endive"
    33, 41, 32, 37, 49, 33,

    // "dindon"
    32, 37, 41, 32, 42, 41,

    // "chervis"
    31, 36, 33, 45, 49, 37, 46,

    // "cresson"
    31, 45, 33, 46, 46, 42, 41,

    // "dentelaire"
    32, 33, 41, 47, 33, 39, 29, 37, 45, 33,

    // "grenade"
    35, 45, 33, 41, 29, 32, 33,

    // "herse"
    36, 33, 45, 46, 33,

    // "bacchante"
    30, 29, 31, 31, 36, 29, 41, 47, 33,

    // "azerole"
    29, 52, 33, 45, 42, 39, 33,

    // "garance"
    35, 29, 45, 29, 41, 31, 33,

    // "orange"
    42, 45, 29, 41, 35, 33,

    // "faisan"
    34, 29, 37, 46, 29, 41,

    // "pistache"
    43, 37, 46, 47, 29, 31, 36, 33,

    // "macjonc"
    40, 29, 31, 38, 42, 41, 31,

    // "coing"
    31, 42, 37, 41, 35,

    // "cormier"
    31, 42, 45, 40, 37, 33, 45,

    // "rouleau"
    45, 42, 48, 39, 33, 29, 48,

    // "raiponce"
    45, 29, 37, 43, 42, 41, 31, 33,

    // "turneps"
    47, 48, 45, 41, 33, 43, 46,

    // "chicorée"
    31, 36, 37, 31, 42, 45, 56, 33,

    // "nèfle"
    41, 55, 34, 39, 33,

    // "cochon"
    31, 42, 31, 36, 42, 41,

    // "mâche"
    40, 54, 31, 36, 33,

    // "chou-fleur"
    31, 36, 42, 48, 13, 34, 39, 33, 48, 45,

    // "miel"
    40, 37, 33, 39,

    // "génépi"
    35, 56, 41, 56, 43, 37,

    // "pioche"
    43, 37, 42, 31, 36, 33,

    // "cire"
    31, 37, 45, 33,

    // "raifort"
    45, 29, 37, 34, 42, 45, 47,

    // "cèdre"
    31, 55, 32, 45, 33,

    // "sapin"
    46, 29, 43, 37, 41,

    // "chevreuil"
    31, 36, 33, 49, 45, 33, 48, 37, 39,

    // "ajonc"
    29, 38, 42, 41, 31,

    // "cyprès"
    31, 51, 43, 45, 55, 46,

    // "lierre"
    39, 37, 33, 45, 45, 33,

    // "sabine"
    46, 29, 30, 37, 41, 33,

    // "hoye"
    36, 42, 51, 33,

    // "érable sucré"
    56, 45, 29, 30, 39, 33, 11, 46, 48, 31, 45, 56,

    // "bruyère"
    30, 45, 48, 51, 55, 45, 33,

    // "roseau"
    45, 42, 46, 33, 29, 48,

    // "oseille"
    42, 46, 33, 37, 39, 39, 33,

    // "grillon"
    35, 45, 37, 39, 39, 42, 41,

    // "pignon"
    43, 37, 35, 41, 42, 41,

    // "liège"
    39, 37, 55, 35, 33,

    // "truffe"
    47, 45, 48, 34, 34, 33,

    // "olive"
    42, 39, 37, 49, 33,

    // "pelle"
    43, 33, 39, 39, 33,

    // "tourbe"
    47, 42, 48, 45, 30, 33,

    // "houille"
    36, 42, 48, 37, 39, 39, 33,

    // "bitume"
    30, 37, 47, 48, 40, 33,

    // "soufre"
    46, 42, 48, 34, 45, 33,

    // "chien"
    31, 36, 37, 33, 41,

    // "lave"
    39, 29, 49, 33,

    // "terre végétale"
    47, 33, 45, 45, 33, 11, 49, 56, 35, 56, 47, 29, 39, 33,

    // "fumier"
    34, 48, 40, 37, 33, 45,

    // "salpêtre"
    46, 29, 39, 43, 57, 47, 45, 33,

    // "fléau"
    34, 39, 56, 29, 48,

    // "granite"
    35, 45, 29, 41, 37, 47, 33,

    // "argile"
    29, 45, 35, 37, 39, 33,

    // "ardoise"
    29, 45, 32, 42, 37, 46, 33,

    // "grès"
    35, 45, 55, 46,

    // "lapin"
    39, 29, 43, 37, 41,

    // "silex"
    46, 37, 39, 33, 50,

    // "marne"
    40, 29, 45, 41, 33,

    // "pierre à chaux"
    43, 37, 33, 45, 45, 33, 11, 53, 11, 31, 36, 29, 48, 50,

    // "marbre"
    40, 29, 45, 30, 45, 33,

    // "van"
    49, 29, 41,

    // "pierre à plâtre"
    43, 37, 33, 45, 45, 33, 11, 53, 11, 43, 39, 54, 47, 45, 33,

    // "sel"
    46, 33, 39,

    // "fer"
    34, 33, 45,

    // "cuivre"
    31, 48, 37, 49, 45, 33,

    // "chat"
    31, 36, 29, 47,

    // "étain"
    56, 47, 29, 37, 41,

    // "plomb"
    43, 39, 42, 40, 30,

    // "zinc"
    52, 37, 41, 31,

    // "mercure"
    40, 33, 45, 31, 48, 45, 33,

    // "crible"
    31, 45, 37, 30, 39, 33,

    // "lauréole"
    39, 29, 48, 45, 56, 42, 39, 33,

    // "mousse"
    40, 42, 48, 46, 46, 33,

    // "fragon"
    34, 45, 29, 35, 42, 41,

    // "pervenche"
    43, 33, 45, 49, 33, 41, 31, 36, 33,

    // "taureau"
    47, 29, 48, 45, 33, 29, 48,

    // "laurier-tin"
    39, 29, 48, 45, 37, 33, 45, 13, 47, 37, 41,

    // "amatyste"
    29, 40, 29, 47, 51, 46, 47, 33,

    // "mézéréon"
    40, 56, 52, 56, 45, 56, 42, 41,

    // "peuplier"
    43, 33, 48, 43, 39, 37, 33, 45,

    // "coignée"
    31, 42, 37, 35, 41, 56, 33,

    // "ellébore"
    33, 39, 39, 56, 30, 42, 45, 33,

    // "brocoli"
    30, 45, 42, 31, 42, 39, 37,

    // "laurier"
    39, 29, 48, 45, 37, 33, 45,

    // "avelinier"
    29, 49, 33, 39, 37, 41, 37, 33, 45,

    // "vache"
    49, 29, 31, 36, 33,

    // "buis"
    30, 48, 37, 46,

    // "lichén"
    39, 37, 31, 36, 56, 41,

    // "if"
    37, 34,

    // "pulmonaire"
    43, 48, 39, 40, 42, 41, 29, 37, 45, 33,

    // "serpette"
    46, 33, 45, 43, 33, 47, 47, 33,

    // "thlaspi"
    47, 36, 39, 29, 46, 43, 37,

    // "thimelé"
    47, 36, 37, 40, 33, 39, 56,

    // "chiendent"
    31, 36, 37, 33, 41, 32, 33, 41, 47,

    // "traînasse"
    47, 45, 29, 58, 41, 29, 46, 46, 33,

    // "lièvre"
    39, 37, 55, 49, 45, 33,

    // "guède"
    35, 48, 55, 32, 33,

    // "noisetier"
    41, 42, 37, 46, 33, 47, 37, 33, 45,

    // "cyclamen"
    31, 51, 31, 39, 29, 40, 33, 41,

    // "chélidoine"
    31, 36, 56, 39, 37, 32, 42, 37, 41, 33,

    // "traîneau"
    47, 45, 29, 58, 41, 33, 29, 48,

    // "tussilage"
    47, 48, 46, 46, 37, 39, 29, 35, 33,

    // "cornouiller"
    31, 42, 45, 41, 42, 48, 37, 39, 39, 33, 45,

    // "violier"
    49, 37, 42, 39, 37, 33, 45,

    // "troène"
    47, 45, 42, 55, 41, 33,

    // "bouc"
    30, 42, 48, 31,

    // "asaret"
    29, 46, 29, 45, 33, 47,

    // "alaterne"
    29, 39, 29, 47, 33, 45, 41, 33,

    // "violette"
    49, 37, 42, 39, 33, 47, 47, 33,

    // "marceau"
    40, 29, 45, 31, 33, 29, 48,

    // "bêche"
    30, 57, 31, 36, 33,

    // "narcisse"
    41, 29, 45, 31, 37, 46, 46, 33,

    // "orme"
    42, 45, 40, 33,

    // "fumeterre"
    34, 48, 40, 33, 47, 33, 45, 45, 33,

    // "vélar"
    49, 56, 39, 29, 45,

    // "chèvre"
    31, 36, 55, 49, 45, 33,

    // "épinard"
    56, 43, 37, 41, 29, 45, 32,

    // "doronic"
    32, 42, 45, 42, 41, 37, 31,

    // "mouron"
    40, 42, 48, 45, 42, 41,

    // "cerfeuil"
    31, 33, 45, 34, 33, 48, 37, 39,

    // "cordeau"
    31, 42, 45, 32, 33, 29, 48,

    // "mandragore"
    40, 29, 41, 32, 45, 29, 35, 42, 45, 33,

    // "persil"
    43, 33, 45, 46, 37, 39,

    // "cochléaria"
    31, 42, 31, 36, 39, 56, 29, 45, 37, 29,

    // "pâquerette"
    43, 54, 44, 48, 33, 45, 33, 47, 47, 33,

    // "thon"
    47, 36, 42, 41,

    // "pissenlit"
    43, 37, 46, 46, 33, 41, 39, 37, 47,

    // "sylvie"
    46, 51, 39, 49, 37, 33,

    // "capillaire"
    31, 29, 43, 37, 39, 39, 29, 37, 45, 33,

    // "frêne"
    34, 45, 57, 41, 33,

    // "plantoir"
    43, 39, 29, 41, 47, 42, 37, 45,

    // "primevère"
    43, 45, 37, 40, 33, 49, 55, 45, 33,

    // "platane"
    43, 39, 29, 47, 29, 41, 33,

    // "asperge"
    29, 46, 43, 33, 45, 35, 33,

    // "tulipe"
    47, 48, 39, 37, 43, 33,

    // "poule"
    43, 42, 48, 39, 33,

    // "bette"
    30, 33, 47, 47, 33,

    // "bouleau"
    30, 42, 48, 39, 33, 29, 48,

    // "jonquille"
    38, 42, 41, 44, 48, 37, 39, 39, 33,

    // "aulne"
    29, 48, 39, 41, 33,

    // "couvoir"
    31, 42, 48, 49, 42, 37, 45,

    // "perce-neige"
    43, 33, 45, 31, 33, 13, 41, 33, 37, 35, 33,

    // "crocus"
    31, 45, 42, 31, 48, 46,

    // "hêtre"
    36, 57, 47, 45, 33,

    // "laitue"
    39, 29, 37, 47, 48, 33,

    // "torillon"
    47, 42, 45, 37, 39, 39, 42, 41,

    // "lilas"
    39, 37, 39, 29, 46,

    // "anémone"
    29, 41, 56, 40, 42, 41, 33,

    // "pensée"
    43, 33, 41, 46, 56, 33,

    // "myrtille"
    40, 51, 45, 47, 37, 39, 39, 33,

    // "greffoir"
    35, 45, 33, 34, 34, 42, 37, 45,

    // "cerisier"
    31, 33, 45, 37, 46, 37, 33, 45,

    // "verveine"
    49, 33, 45, 49, 33, 37, 41, 33,

    // "grenadier"
    35, 45, 33, 41, 29, 32, 37, 33, 45,

    // "vernal"
    49, 33, 45, 41, 29, 39,

    // "cheval"
    31, 36, 33, 49, 29, 39,

    // "brenèche"
    30, 45, 33, 41, 55, 31, 36, 33,

    // "charme"
    31, 36, 29, 45, 40, 33,

    // "morille"
    40, 42, 45, 37, 39, 39, 33,

    // "hêtre enraciné"
    36, 57, 47, 45, 33, 11, 33, 41, 45, 29, 31, 37, 41, 56,

    // "ruche"
    45, 48, 31, 36, 33,

    // "rose"
    45, 42, 46, 33,

    // "chêne"
    31, 36, 57, 41, 33,

    // "fougère"
    34, 42, 48, 35, 55, 45, 33,

    // "aubépine"
    29, 48, 30, 56, 43, 37, 41, 33,

    // "rossignol"
    45, 42, 46, 46, 37, 35, 41, 42, 39,

    // "ancolie"
    29, 41, 31, 42, 39, 37, 33,

    // "muguet"
    40, 48, 35, 48, 33, 47,

    // "champignon"
    31, 36, 29, 40, 43, 37, 35, 41, 42, 41,

    // "hyacinthe"
    36, 51, 29, 31, 37, 41, 47, 36, 33,

    // "râteau"
    45, 54, 47, 33, 29, 48,

    // "rhubarbe"
    45, 36, 48, 30, 29, 45, 30, 33,

    // "sainfoin"
    46, 29, 37, 41, 34, 42, 37, 41,

    // "bâton-d'or"
    30, 54, 47, 42, 41, 13, 32, 12, 42, 45,

    // "chamerisier"
    31, 36, 29, 40, 33, 45, 37, 46, 37, 33, 45,

    // "ver à soie"
    49, 33, 45, 11, 53, 11, 46, 42, 37, 33,

    // "consoude"
    31, 42, 41, 46, 42, 48, 32, 33,

    // "pimprenelle"
    43, 37, 40, 43, 45, 33, 41, 33, 39, 39, 33,

    // "corbeille d'or"
    31, 42, 45, 30, 33, 37, 39, 39, 33, 11, 32, 12, 42, 45,

    // "arroche"
    29, 45, 45, 42, 31, 36, 33,

    // "sarcloir"
    46, 29, 45, 31, 39, 42, 37, 45,

    // "statice"
    46, 47, 29, 47, 37, 31, 33,

    // "fritillaire"
    34, 45, 37, 47, 37, 39, 39, 29, 37, 45, 33,

    // "bourache"
    30, 42, 48, 45, 29, 31, 36, 33,

    // "valériane"
    49, 29, 39, 56, 45, 37, 29, 41, 33,

    // "carpe"
    31, 29, 45, 43, 33,

    // "fusain"
    34, 48, 46, 29, 37, 41,

    // "civette"
    31, 37, 49, 33, 47, 47, 33,

    // "buglosse"
    30, 48, 35, 39, 42, 46, 46, 33,

    // "sénevé"
    46, 56, 41, 33, 49, 56,

    // "houlette"
    36, 42, 48, 39, 33, 47, 47, 33,

    // "luzerne"
    39, 48, 52, 33, 45, 41, 33,

    // "hémérocalle"
    36, 56, 40, 56, 45, 42, 31, 29, 39, 39, 33,

    // "trèfle"
    47, 45, 55, 34, 39, 33,

    // "angélique"
    29, 41, 35, 56, 39, 37, 44, 48, 33,

    // "canard"
    31, 29, 41, 29, 45, 32,

    // "mélisse"
    40, 56, 39, 37, 46, 46, 33,

    // "fromental"
    34, 45, 42, 40, 33, 41, 47, 29, 39,

    // "martagon"
    40, 29, 45, 47, 29, 35, 42, 41,

    // "serpolet"
    46, 33, 45, 43, 42, 39, 33, 47,

    // "faux"
    34, 29, 48, 50,

    // "fraise"
    34, 45, 29, 37, 46, 33,

    // "bétoine"
    30, 56, 47, 42, 37, 41, 33,

    // "pois"
    43, 42, 37, 46,

    // "acacia"
    29, 31, 29, 31, 37, 29,

    // "caille"
    31, 29, 37, 39, 39, 33,

    // "œillet"
    62, 37, 39, 39, 33, 47,

    // "sureau"
    46, 48, 45, 33, 29, 48,

    // "pavot"
    43, 29, 49, 42, 47,

    // "tilleul"
    47, 37, 39, 39, 33, 48, 39,

    // "fourche"
    34, 42, 48, 45, 31, 36, 33,

    // "barbeau"
    30, 29, 45, 30, 33, 29, 48,

    // "camomille"
    31, 29, 40, 42, 40, 37, 39, 39, 33,

    // "chévrefeuille"
    31, 36, 56, 49, 45, 33, 34, 33, 48, 37, 39, 39, 33,

    // "caille-lait"
    31, 29, 37, 39, 39, 33, 13, 39, 29, 37, 47,

    // "tanche"
    47, 29, 41, 31, 36, 33,

    // "jasmin"
    38, 29, 46, 40, 37, 41,

    // "verveine"
    49, 33, 45, 49, 33, 37, 41, 33,

    // "thym"
    47, 36, 51, 40,

    // "pivoine"
    43, 37, 49, 42, 37, 41, 33,

    // "chariot"
    31, 36, 29, 45, 37, 42, 47,

    // "seigle"
    46, 33, 37, 35, 39, 33,

    // "avoine"
    29, 49, 42, 37, 41, 33,

    // "oignon"
    42, 37, 35, 41, 42, 41,

    // "véronique"
    49, 56, 45, 42, 41, 37, 44, 48, 33,

    // "mulet"
    40, 48, 39, 33, 47,

    // "romaine"
    45, 42, 40, 29, 37, 41, 33,

    // "concombre"
    31, 42, 41, 31, 42, 40, 30, 45, 33,

    // "échalote"
    56, 31, 36, 29, 39, 42, 47, 33,

    // "absinthe"
    29, 30, 46, 37, 41, 47, 36, 33,

    // "faucille"
    34, 29, 48, 31, 37, 39, 39, 33,

    // "coriandre"
    31, 42, 45, 37, 29, 41, 32, 45, 33,

    // "artichaut"
    29, 45, 47, 37, 31, 36, 29, 48, 47,

    // "girofle"
    35, 37, 45, 42, 34, 39, 33,

    // "lavande"
    39, 29, 49, 29, 41, 32, 33,

    // "chamois"
    31, 36, 29, 40, 42, 37, 46,

    // "tabac"
    47, 29, 30, 29, 31,

    // "groseille"
    35, 45, 42, 46, 33, 37, 39, 39, 33,

    // "gesse"
    35, 33, 46, 46, 33,

    // "cerise"
    31, 33, 45, 37, 46, 33,

    // "parc"
    43, 29, 45, 31,

    // "menthe"
    40, 33, 41, 47, 36, 33,

    // "cumin"
    31, 48, 40, 37, 41,

    // "haricot"
    36, 29, 45, 37, 31, 42, 47,

    // "orcanète"
    42, 45, 31, 29, 41, 55, 47, 33,

    // "pintade"
    43, 37, 41, 47, 29, 32, 33,

    // "sauge"
    46, 29, 48, 35, 33,

    // "ail"
    29, 37, 39,

    // "vesce"
    49, 33, 46, 31, 33,

    // "blé"
    30, 39, 56,

    // "chalémie"
    31, 36, 29, 39, 56, 40, 37, 33,

    // "épeautre"
    56, 43, 33, 29, 48, 47, 45, 33,

    // "bouillon-blanc"
    30, 42, 48, 37, 39, 39, 42, 41, 13, 30, 39, 29, 41, 31,

    // "melon"
    40, 33, 39, 42, 41,

    // "ivraie"
    37, 49, 45, 29, 37, 33,

    // "bélier"
    30, 56, 39, 37, 33, 45,

    // "prêle"
    43, 45, 57, 39, 33,

    // "armoise"
    29, 45, 40, 42, 37, 46, 33,

    // "carthame"
    31, 29, 45, 47, 36, 29, 40, 33,

    // "mûre"
    40, 61, 45, 33,

    // "arrosoir"
    29, 45, 45, 42, 46, 42, 37, 45,

    // "panis"
    43, 29, 41, 37, 46,

    // "salicorne"
    46, 29, 39, 37, 31, 42, 45, 41, 33,

    // "abricot"
    29, 30, 45, 37, 31, 42, 47,

    // "basilic"
    30, 29, 46, 37, 39, 37, 31,

    // "brebis"
    30, 45, 33, 30, 37, 46,

    // "guimauve"
    35, 48, 37, 40, 29, 48, 49, 33,

    // "lin"
    39, 37, 41,

    // "amande"
    29, 40, 29, 41, 32, 33,

    // "gentiane"
    35, 33, 41, 47, 37, 29, 41, 33,

    // "écluse"
    56, 31, 39, 48, 46, 33,

    // "carline"
    31, 29, 45, 39, 37, 41, 33,

    // "câprier"
    31, 54, 43, 45, 37, 33, 45,

    // "lentille"
    39, 33, 41, 47, 37, 39, 39, 33,

    // "aunée"
    29, 48, 41, 56, 33,

    // "loutre"
    39, 42, 48, 47, 45, 33,

    // "myrte"
    40, 51, 45, 47, 33,

    // "colza"
    31, 42, 39, 52, 29,

    // "lupin"
    39, 48, 43, 37, 41,

    // "coton"
    31, 42, 47, 42, 41,

    // "moulin"
    40, 42, 48, 39, 37, 41,

    // "prune"
    43, 45, 48, 41, 33,

    // "millet"
    40, 37, 39, 39, 33, 47,

    // "lycoperdon"
    39, 51, 31, 42, 43, 33, 45, 32, 42, 41,

    // "escourgeon"
    33, 46, 31, 42, 48, 45, 35, 33, 42, 41,

    // "saumon"
    46, 29, 48, 40, 42, 41,

    // "tubéreuse"
    47, 48, 30, 56, 45, 33, 48, 46, 33,

    // "sucrion"
    46, 48, 31, 45, 37, 42, 41,

    // "apocyn"
    29, 43, 42, 31, 51, 41,

    // "réglisse"
    45, 56, 35, 39, 37, 46, 46, 33,

    // "échelle"
    56, 31, 36, 33, 39, 39, 33,

    // "pastèque"
    43, 29, 46, 47, 55, 44, 48, 33,

    // "fenouil"
    34, 33, 41, 42, 48, 37, 39,

    // "épine-vinette"
    56, 43, 37, 41, 33, 13, 49, 37, 41, 33, 47, 47, 33,

    // "noix"
    41, 42, 37, 50,

    // "truite"
    47, 45, 48, 37, 47, 33,

    // "citron"
    31, 37, 47, 45, 42, 41,

    // "cardère"
    31, 29, 45, 32, 55, 45, 33,

    // "nerprun"
    41, 33, 45, 43, 45, 48, 41,

    // "tagette"
    47, 29, 35, 33, 47, 47, 33,

    // "hotte"
    36, 42, 47, 47, 33,

    // "églantier"
    56, 35, 39, 29, 41, 47, 37, 33, 45,

    // "noisette"
    41, 42, 37, 46, 33, 47, 47, 33,

    // "houblon"
    36, 42, 48, 30, 39, 42, 41,

    // "sorgho"
    46, 42, 45, 35, 36, 42,

    // "écrevisse"
    56, 31, 45, 33, 49, 37, 46, 46, 33,

    // "bigarade"
    30, 37, 35, 29, 45, 29, 32, 33,

    // "verge d'or"
    49, 33, 45, 35, 33, 11, 32, 12, 42, 45,

    // "maïs"
    40, 29, 59, 46,

    // "marron"
    40, 29, 45, 45, 42, 41,

    // "panier"
    43, 29, 41, 37, 33, 45
};

// Fragment begin positions
const std::array<uint16_t, fragment_count> fragment_begin = {
    0, // nr: "0"
    1, // "1"
    2, // "2"
    3, // "3"
    4, // "4"
    5, // "5"
    6, // "6"
    7, // "7"
    8, // "8"
    9, // "9"
    10, // colon: ":"
    11, // space: " "
    12, // bell: "🔔"
    13, // run: "run"
    16, // stop: "stop"
    20, // alarm: "alarm"
    25, // hour: "hour"
    29, // minute: "minute"
    35, // set: "set"
    38, // day: "day"
    41, // month: "month"
    46, // year: "year"
    50, // annee: "Année "
    56, // decade: " Décade "
    64, // jourdu: "Jour du "
    72, // jourepagomene: "Jour épagomène"
    86, // on_off: "on"
    88, // "off"
    91, // months: "Vendémiaire"
    102, // "Brumaire"
    110, // "Frimaire"
    118, // "Nivôse"
    124, // "Pluviôse"
    132, // "Ventôse"
    139, // "Germinal"
    147, // "Floréal"
    154, // "Prairial"
    162, // "Messidor"
    170, // "Thermidor"
    179, // "Fructidor"
    188, // days: "Primidi"
    195, // "Duodi"
    200, // "Tridi"
    205, // "Quartidi"
    213, // "Quintidi"
    221, // "Sextidi"
    228, // "Septidi"
    235, // "Octidi"
    241, // "Nonidi"
    247, // "Décadi"
    253, // sansculottides: "Fête de la Vertu"
    269, // "Fête du Génie"
    282, // "Fête du Travail"
    297, // "Fête de l'Opinion"
    314, // "Fête des Récompenses"
    334, // "Fête de la Révolution"
    355, // day_of_year: "raisin"
    361, // "safran"
    367, // "châtaigne"
    376, // "colchique"
    385, // "cheval"
    391, // "balsamine"
    400, // "carotte"
    407, // "amarante"
    415, // "panais"
    421, // "cuve"
    425, // "pomme de terre"
    439, // "immortelle"
    449, // "potiron"
    456, // "réséda"
    462, // "âne"
    465, // "belle de nuit"
    478, // "citrouille"
    488, // "sarrasin"
    496, // "tournesol"
    505, // "pressoir"
    513, // "chanvre"
    520, // "pêche"
    525, // "navet"
    530, // "amaryllis"
    539, // "bœuf"
    543, // "aubergine"
    552, // "piment"
    558, // "tomate"
    564, // "orge"
    568, // "tonneau"
    575, // "pomme"
    580, // "céleri"
    586, // "poire"
    591, // "betterave"
    600, // "oie"
    603, // "héliotrope"
    613, // "figue"
    618, // "scorsonère"
    628, // "alisier"
    635, // "charrue"
    642, // "salsifis"
    650, // "macre"
    655, // "topinambour"
    666, // "endive"
    672, // "dindon"
    678, // "chervis"
    685, // "cresson"
    692, // "dentelaire"
    702, // "grenade"
    709, // "herse"
    714, // "bacchante"
    723, // "azerole"
    730, // "garance"
    737, // "orange"
    743, // "faisan"
    749, // "pistache"
    757, // "macjonc"
    764, // "coing"
    769, // "cormier"
    776, // "rouleau"
    783, // "raiponce"
    791, // "turneps"
    798, // "chicorée"
    806, // "nèfle"
    811, // "cochon"
    817, // "mâche"
    822, // "chou-fleur"
    832, // "miel"
    836, // "génépi"
    842, // "pioche"
    848, // "cire"
    852, // "raifort"
    859, // "cèdre"
    864, // "sapin"
    869, // "chevreuil"
    878, // "ajonc"
    883, // "cyprès"
    889, // "lierre"
    895, // "sabine"
    901, // "hoye"
    905, // "érable sucré"
    917, // "bruyère"
    924, // "roseau"
    930, // "oseille"
    937, // "grillon"
    944, // "pignon"
    950, // "liège"
    955, // "truffe"
    961, // "olive"
    966, // "pelle"
    971, // "tourbe"
    977, // "houille"
    984, // "bitume"
    990, // "soufre"
    996, // "chien"
    1001, // "lave"
    1005, // "terre végétale"
    1019, // "fumier"
    1025, // "salpêtre"
    1033, // "fléau"
    1038, // "granite"
    1045, // "argile"
    1051, // "ardoise"
    1058, // "grès"
    1062, // "lapin"
    1067, // "silex"
    1072, // "marne"
    1077, // "pierre à chaux"
    1091, // "marbre"
    1097, // "van"
    1100, // "pierre à plâtre"
    1115, // "sel"
    1118, // "fer"
    1121, // "cuivre"
    1127, // "chat"
    1131, // "étain"
    1136, // "plomb"
    1141, // "zinc"
    1145, // "mercure"
    1152, // "crible"
    1158, // "lauréole"
    1166, // "mousse"
    1172, // "fragon"
    1178, // "pervenche"
    1187, // "taureau"
    1194, // "laurier-tin"
    1205, // "amatyste"
    1213, // "mézéréon"
    1221, // "peuplier"
    1229, // "coignée"
    1236, // "ellébore"
    1244, // "brocoli"
    1251, // "laurier"
    1258, // "avelinier"
    1267, // "vache"
    1272, // "buis"
    1276, // "lichén"
    1282, // "if"
    1284, // "pulmonaire"
    1294, // "serpette"
    1302, // "thlaspi"
    1309, // "thimelé"
    1316, // "chiendent"
    1325, // "traînasse"
    1334, // "lièvre"
    1340, // "guède"
    1345, // "noisetier"
    1354, // "cyclamen"
    1362, // "chélidoine"
    1372, // "traîneau"
    1380, // "tussilage"
    1389, // "cornouiller"
    1400, // "violier"
    1407, // "troène"
    1413, // "bouc"
    1417, // "asaret"
    1423, // "alaterne"
    1431, // "violette"
    1439, // "marceau"
    1446, // "bêche"
    1451, // "narcisse"
    1459, // "orme"
    1463, // "fumeterre"
    1472, // "vélar"
    1477, // "chèvre"
    1483, // "épinard"
    1490, // "doronic"
    1497, // "mouron"
    1503, // "cerfeuil"
    1511, // "cordeau"
    1518, // "mandragore"
    1528, // "persil"
    1534, // "cochléaria"
    1544, // "pâquerette"
    1554, // "thon"
    1558, // "pissenlit"
    1567, // "sylvie"
    1573, // "capillaire"
    1583, // "frêne"
    1588, // "plantoir"
    1596, // "primevère"
    1605, // "platane"
    1612, // "asperge"
    1619, // "tulipe"
    1625, // "poule"
    1630, // "bette"
    1635, // "bouleau"
    1642, // "jonquille"
    1651, // "aulne"
    1656, // "couvoir"
    1663, // "perce-neige"
    1674, // "crocus"
    1680, // "hêtre"
    1685, // "laitue"
    1691, // "torillon"
    1699, // "lilas"
    1704, // "anémone"
    1711, // "pensée"
    1717, // "myrtille"
    1725, // "greffoir"
    1733, // "cerisier"
    1741, // "verveine"
    1749, // "grenadier"
    1758, // "vernal"
    1764, // "cheval"
    1770, // "brenèche"
    1778, // "charme"
    1784, // "morille"
    1791, // "hêtre enraciné"
    1805, // "ruche"
    1810, // "rose"
    1814, // "chêne"
    1819, // "fougère"
    1826, // "aubépine"
    1834, // "rossignol"
    1843, // "ancolie"
    1850, // "muguet"
    1856, // "champignon"
    1866, // "hyacinthe"
    1875, // "râteau"
    1881, // "rhubarbe"
    1889, // "sainfoin"
    1897, // "bâton-d'or"
    1907, // "chamerisier"
    1918, // "ver à soie"
    1928, // "consoude"
    1936, // "pimprenelle"
    1947, // "corbeille d'or"
    1961, // "arroche"
    1968, // "sarcloir"
    1976, // "statice"
    1983, // "fritillaire"
    1994, // "bourache"
    2002, // "valériane"
    2011, // "carpe"
    2016, // "fusain"
    2022, // "civette"
    2029, // "buglosse"
    2037, // "sénevé"
    2043, // "houlette"
    2051, // "luzerne"
    2058, // "hémérocalle"
    2069, // "trèfle"
    2075, // "angélique"
    2084, // "canard"
    2090, // "mélisse"
    2097, // "fromental"
    2106, // "martagon"
    2114, // "serpolet"
    2122, // "faux"
    2126, // "fraise"
    2132, // "bétoine"
    2139, // "pois"
    2143, // "acacia"
    2149, // "caille"
    2155, // "œillet"
    2161, // "sureau"
    2167, // "pavot"
    2172, // "tilleul"
    2179, // "fourche"
    2186, // "barbeau"
    2193, // "camomille"
    2202, // "chévrefeuille"
    2215, // "caille-lait"
    2226, // "tanche"
    2232, // "jasmin"
    2238, // "verveine"
    2246, // "thym"
    2250, // "pivoine"
    2257, // "chariot"
    2264, // "seigle"
    2270, // "avoine"
    2276, // "oignon"
    2282, // "véronique"
    2291, // "mulet"
    2296, // "romaine"
    2303, // "concombre"
    2312, // "échalote"
    2320, // "absinthe"
    2328, // "faucille"
    2336, // "coriandre"
    2345, // "artichaut"
    2354, // "girofle"
    2361, // "lavande"
    2368, // "chamois"
    2375, // "tabac"
    2380, // "groseille"
    2389, // "gesse"
    2394, // "cerise"
    2400, // "parc"
    2404, // "menthe"
    2410, // "cumin"
    2415, // "haricot"
    2422, // "orcanète"
    2430, // "pintade"
    2437, // "sauge"
    2442, // "ail"
    2445, // "vesce"
    2450, // "blé"
    2453, // "chalémie"
    2461, // "épeautre"
    2469, // "bouillon-blanc"
    2483, // "melon"
    2488, // "ivraie"
    2494, // "bélier"
    2500, // "prêle"
    2505, // "armoise"
    2512, // "carthame"
    2520, // "mûre"
    2524, // "arrosoir"
    2532, // "panis"
    2537, // "salicorne"
    2546, // "abricot"
    2553, // "basilic"
    2560, // "brebis"
    2566, // "guimauve"
    2574, // "lin"
    2577, // "amande"
    2583, // "gentiane"
    2591, // "écluse"
    2597, // "carline"
    2604, // "câprier"
    2611, // "lentille"
    2619, // "aunée"
    2624, // "loutre"
    2630, // "myrte"
    2635, // "colza"
    2640, // "lupin"
    2645, // "coton"
    2650, // "moulin"
    2656, // "prune"
    2661, // "millet"
    2667, // "lycoperdon"
    2677, // "escourgeon"
    2687, // "saumon"
    2693, // "tubéreuse"
    2702, // "sucrion"
    2709, // "apocyn"
    2715, // "réglisse"
    2723, // "échelle"
    2730, // "pastèque"
    2738, // "fenouil"
    2745, // "épine-vinette"
    2758, // "noix"
    2762, // "truite"
    2768, // "citron"
    2774, // "cardère"
    2781, // "nerprun"
    2788, // "tagette"
    2795, // "hotte"
    2800, // "églantier"
    2809, // "noisette"
    2817, // "houblon"
    2824, // "sorgho"
    2830, // "écrevisse"
    2839, // "bigarade"
    2847, // "verge d'or"
    2857, // "maïs"
    2861, // "marron"
    2867, // "panier"
};

// Fragment lengths
const std::array<uint16_t, fragment_count> fragment_len = {
    1, // nr: "0"
    1, // "1"
    1, // "2"
    1, // "3"
    1, // "4"
    1, // "5"
    1, // "6"
    1, // "7"
    1, // "8"
    1, // "9"
    1, // colon: ":"
    1, // space: " "
    1, // bell: "🔔"
    3, // run: "run"
    4, // stop: "stop"
    5, // alarm: "alarm"
    4, // hour: "hour"
    6, // minute: "minute"
    3, // set: "set"
    3, // day: "day"
    5, // month: "month"
    4, // year: "year"
    6, // annee: "Année "
    8, // decade: " Décade "
    8, // jourdu: "Jour du "
    14, // jourepagomene: "Jour épagomène"
    2, // on_off: "on"
    3, // "off"
    11, // months: "Vendémiaire"
    8, // "Brumaire"
    8, // "Frimaire"
    6, // "Nivôse"
    8, // "Pluviôse"
    7, // "Ventôse"
    8, // "Germinal"
    7, // "Floréal"
    8, // "Prairial"
    8, // "Messidor"
    9, // "Thermidor"
    9, // "Fructidor"
    7, // days: "Primidi"
    5, // "Duodi"
    5, // "Tridi"
    8, // "Quartidi"
    8, // "Quintidi"
    7, // "Sextidi"
    7, // "Septidi"
    6, // "Octidi"
    6, // "Nonidi"
    6, // "Décadi"
    16, // sansculottides: "Fête de la Vertu"
    13, // "Fête du Génie"
    15, // "Fête du Travail"
    17, // "Fête de l'Opinion"
    20, // "Fête des Récompenses"
    21, // "Fête de la Révolution"
    6, // day_of_year: "raisin"
    6, // "safran"
    9, // "châtaigne"
    9, // "colchique"
    6, // "cheval"
    9, // "balsamine"
    7, // "carotte"
    8, // "amarante"
    6, // "panais"
    4, // "cuve"
    14, // "pomme de terre"
    10, // "immortelle"
    7, // "potiron"
    6, // "réséda"
    3, // "âne"
    13, // "belle de nuit"
    10, // "citrouille"
    8, // "sarrasin"
    9, // "tournesol"
    8, // "pressoir"
    7, // "chanvre"
    5, // "pêche"
    5, // "navet"
    9, // "amaryllis"
    4, // "bœuf"
    9, // "aubergine"
    6, // "piment"
    6, // "tomate"
    4, // "orge"
    7, // "tonneau"
    5, // "pomme"
    6, // "céleri"
    5, // "poire"
    9, // "betterave"
    3, // "oie"
    10, // "héliotrope"
    5, // "figue"
    10, // "scorsonère"
    7, // "alisier"
    7, // "charrue"
    8, // "salsifis"
    5, // "macre"
    11, // "topinambour"
    6, // "endive"
    6, // "dindon"
    7, // "chervis"
    7, // "cresson"
    10, // "dentelaire"
    7, // "grenade"
    5, // "herse"
    9, // "bacchante"
    7, // "azerole"
    7, // "garance"
    6, // "orange"
    6, // "faisan"
    8, // "pistache"
    7, // "macjonc"
    5, // "coing"
    7, // "cormier"
    7, // "rouleau"
    8, // "raiponce"
    7, // "turneps"
    8, // "chicorée"
    5, // "nèfle"
    6, // "cochon"
    5, // "mâche"
    10, // "chou-fleur"
    4, // "miel"
    6, // "génépi"
    6, // "pioche"
    4, // "cire"
    7, // "raifort"
    5, // "cèdre"
    5, // "sapin"
    9, // "chevreuil"
    5, // "ajonc"
    6, // "cyprès"
    6, // "lierre"
    6, // "sabine"
    4, // "hoye"
    12, // "érable sucré"
    7, // "bruyère"
    6, // "roseau"
    7, // "oseille"
    7, // "grillon"
    6, // "pignon"
    5, // "liège"
    6, // "truffe"
    5, // "olive"
    5, // "pelle"
    6, // "tourbe"
    7, // "houille"
    6, // "bitume"
    6, // "soufre"
    5, // "chien"
    4, // "lave"
    14, // "terre végétale"
    6, // "fumier"
    8, // "salpêtre"
    5, // "fléau"
    7, // "granite"
    6, // "argile"
    7, // "ardoise"
    4, // "grès"
    5, // "lapin"
    5, // "silex"
    5, // "marne"
    14, // "pierre à chaux"
    6, // "marbre"
    3, // "van"
    15, // "pierre à plâtre"
    3, // "sel"
    3, // "fer"
    6, // "cuivre"
    4, // "chat"
    5, // "étain"
    5, // "plomb"
    4, // "zinc"
    7, // "mercure"
    6, // "crible"
    8, // "lauréole"
    6, // "mousse"
    6, // "fragon"
    9, // "pervenche"
    7, // "taureau"
    11, // "laurier-tin"
    8, // "amatyste"
    8, // "mézéréon"
    8, // "peuplier"
    7, // "coignée"
    8, // "ellébore"
    7, // "brocoli"
    7, // "laurier"
    9, // "avelinier"
    5, // "vache"
    4, // "buis"
    6, // "lichén"
    2, // "if"
    10, // "pulmonaire"
    8, // "serpette"
    7, // "thlaspi"
    7, // "thimelé"
    9, // "chiendent"
    9, // "traînasse"
    6, // "lièvre"
    5, // "guède"
    9, // "noisetier"
    8, // "cyclamen"
    10, // "chélidoine"
    8, // "traîneau"
    9, // "tussilage"
    11, // "cornouiller"
    7, // "violier"
    6, // "troène"
    4, // "bouc"
    6, // "asaret"
    8, // "alaterne"
    8, // "violette"
    7, // "marceau"
    5, // "bêche"
    8, // "narcisse"
    4, // "orme"
    9, // "fumeterre"
    5, // "vélar"
    6, // "chèvre"
    7, // "épinard"
    7, // "doronic"
    6, // "mouron"
    8, // "cerfeuil"
    7, // "cordeau"
    10, // "mandragore"
    6, // "persil"
    10, // "cochléaria"
    10, // "pâquerette"
    4, // "thon"
    9, // "pissenlit"
    6, // "sylvie"
    10, // "capillaire"
    5, // "frêne"
    8, // "plantoir"
    9, // "primevère"
    7, // "platane"
    7, // "asperge"
    6, // "tulipe"
    5, // "poule"
    5, // "bette"
    7, // "bouleau"
    9, // "jonquille"
    5, // "aulne"
    7, // "couvoir"
    11, // "perce-neige"
    6, // "crocus"
    5, // "hêtre"
    6, // "laitue"
    8, // "torillon"
    5, // "lilas"
    7, // "anémone"
    6, // "pensée"
    8, // "myrtille"
    8, // "greffoir"
    8, // "cerisier"
    8, // "verveine"
    9, // "grenadier"
    6, // "vernal"
    6, // "cheval"
    8, // "brenèche"
    6, // "charme"
    7, // "morille"
    14, // "hêtre enraciné"
    5, // "ruche"
    4, // "rose"
    5, // "chêne"
    7, // "fougère"
    8, // "aubépine"
    9, // "rossignol"
    7, // "ancolie"
    6, // "muguet"
    10, // "champignon"
    9, // "hyacinthe"
    6, // "râteau"
    8, // "rhubarbe"
    8, // "sainfoin"
    10, // "bâton-d'or"
    11, // "chamerisier"
    10, // "ver à soie"
    8, // "consoude"
    11, // "pimprenelle"
    14, // "corbeille d'or"
    7, // "arroche"
    8, // "sarcloir"
    7, // "statice"
    11, // "fritillaire"
    8, // "bourache"
    9, // "valériane"
    5, // "carpe"
    6, // "fusain"
    7, // "civette"
    8, // "buglosse"
    6, // "sénevé"
    8, // "houlette"
    7, // "luzerne"
    11, // "hémérocalle"
    6, // "trèfle"
    9, // "angélique"
    6, // "canard"
    7, // "mélisse"
    9, // "fromental"
    8, // "martagon"
    8, // "serpolet"
    4, // "faux"
    6, // "fraise"
    7, // "bétoine"
    4, // "pois"
    6, // "acacia"
    6, // "caille"
    6, // "œillet"
    6, // "sureau"
    5, // "pavot"
    7, // "tilleul"
    7, // "fourche"
    7, // "barbeau"
    9, // "camomille"
    13, // "chévrefeuille"
    11, // "caille-lait"
    6, // "tanche"
    6, // "jasmin"
    8, // "verveine"
    4, // "thym"
    7, // "pivoine"
    7, // "chariot"
    6, // "seigle"
    6, // "avoine"
    6, // "oignon"
    9, // "véronique"
    5, // "mulet"
    7, // "romaine"
    9, // "concombre"
    8, // "échalote"
    8, // "absinthe"
    8, // "faucille"
    9, // "coriandre"
    9, // "artichaut"
    7, // "girofle"
    7, // "lavande"
    7, // "chamois"
    5, // "tabac"
    9, // "groseille"
    5, // "gesse"
    6, // "cerise"
    4, // "parc"
    6, // "menthe"
    5, // "cumin"
    7, // "haricot"
    8, // "orcanète"
    7, // "pintade"
    5, // "sauge"
    3, // "ail"
    5, // "vesce"
    3, // "blé"
    8, // "chalémie"
    8, // "épeautre"
    14, // "bouillon-blanc"
    5, // "melon"
    6, // "ivraie"
    6, // "bélier"
    5, // "prêle"
    7, // "armoise"
    8, // "carthame"
    4, // "mûre"
    8, // "arrosoir"
    5, // "panis"
    9, // "salicorne"
    7, // "abricot"
    7, // "basilic"
    6, // "brebis"
    8, // "guimauve"
    3, // "lin"
    6, // "amande"
    8, // "gentiane"
    6, // "écluse"
    7, // "carline"
    7, // "câprier"
    8, // "lentille"
    5, // "aunée"
    6, // "loutre"
    5, // "myrte"
    5, // "colza"
    5, // "lupin"
    5, // "coton"
    6, // "moulin"
    5, // "prune"
    6, // "millet"
    10, // "lycoperdon"
    10, // "escourgeon"
    6, // "saumon"
    9, // "tubéreuse"
    7, // "sucrion"
    6, // "apocyn"
    8, // "réglisse"
    7, // "échelle"
    8, // "pastèque"
    7, // "fenouil"
    13, // "épine-vinette"
    4, // "noix"
    6, // "truite"
    6, // "citron"
    7, // "cardère"
    7, // "nerprun"
    7, // "tagette"
    5, // "hotte"
    9, // "églantier"
    8, // "noisette"
    7, // "houblon"
    6, // "sorgho"
    9, // "écrevisse"
    8, // "bigarade"
    10, // "verge d'or"
    4, // "maïs"
    6, // "marron"
    6, // "panier"
};

// big font character widths
const std::array<uint8_t, big_font_len> big_font_char_widths = {
    19, // '0'
    14, // '1'
    19, // '2'
    19, // '3'
    20, // '4'
    18, // '5'
    19, // '6'
    19, // '7'
    19, // '8'
    19, // '9'
    7, // ':'
};

// big font character begin positions
const std::array<uint16_t, big_font_len> big_font_char_begin = {
    0, // '0'
    117, // '1'
    195, // '2'
    312, // '3'
    429, // '4'
    546, // '5'
    663, // '6'
    780, // '7'
    897, // '8'
    1014, // '9'
    1131, // ':'
};

// big font content (bitmap data, packed)
const std::array<uint8_t, 1170> big_font_content = {
    // '0'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //        #####       
    //     #########      
    //     #########      
    //     ##########     
    //    #####   ####    
    //    ####    ####    
    //   #####     ###    
    //   #####     #####  
    //   ###       #####  
    //   ###       #####  
    //   ###       #####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //  ####       #####  
    //   ###       #####  
    //   ###       #####  
    //   ###       #####  
    //   #####     #####  
    //   #####     ###    
    //   #####    ####    
    //    #####   ####    
    //    #####   ####    
    //    ###########     
    //     #########      
    //        #####       
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0xF0,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x0F,
    0xFC,
    0x00,
    0x1F,
    0x1E,
    0x00,
    0x1E,
    0x1E,
    0x00,
    0x3E,
    0x0E,
    0x00,
    0x3E,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x3E,
    0x0E,
    0x00,
    0x3E,
    0x1E,
    0x00,
    0x1F,
    0x1E,
    0x00,
    0x1F,
    0x1E,
    0x00,
    0x1F,
    0xFC,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x01,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,

    // '1'
    //               
    //               
    //               
    //               
    //               
    //               
    //               
    //               
    //               
    //         ####  
    //        #####  
    //        #####  
    //       ######  
    //     ########  
    //    #########  
    //   ##### ####  
    //  #####  ####  
    //   ##    ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //         ####  
    //               
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xF0,
    0x01,
    0xF0,
    0x01,
    0xF0,
    0x03,
    0xF0,
    0x0F,
    0xF0,
    0x1F,
    0xF0,
    0x3E,
    0xF0,
    0x7C,
    0xF0,
    0x30,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0x00,

    // '2'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //      #######       
    //    ##########      
    //    ##########      
    //  #############     
    //   #####   #####    
    //    #       ####    
    //             ###    
    //             ###    
    //             ###    
    //             ###    
    //            ####    
    //            ####    
    //            ####    
    //           ####     
    //           ####     
    //          ####      
    //          ####      
    //         ####       
    //        ####        
    //        ####        
    //      #####         
    //     #####          
    //    ######          
    //    #####           
    //   #####            
    //   #####            
    //  ################  
    //  ################  
    //  ################  
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x1F,
    0xF8,
    0x00,
    0x1F,
    0xF8,
    0x00,
    0x7F,
    0xFC,
    0x00,
    0x3E,
    0x3E,
    0x00,
    0x10,
    0x1E,
    0x00,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0xF0,
    0x00,
    0x01,
    0xE0,
    0x00,
    0x01,
    0xE0,
    0x00,
    0x07,
    0xC0,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x1F,
    0x80,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x00,
    0x7F,
    0xFF,
    0x80,
    0x7F,
    0xFF,
    0x80,
    0x7F,
    0xFF,
    0x80,
    0x00,
    0x00,
    0x00,

    // '3'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //      #######       
    //    ###########     
    //    ###########     
    //  #############     
    //   ###     #####    
    //    #       ####    
    //             ###    
    //             #####  
    //             ###    
    //            ####    
    //            ####    
    //          #####     
    //     #########      
    //     ########       
    //     ########       
    //     ##########     
    //           #####    
    //            ####    
    //             #####  
    //             #####  
    //             #####  
    //             #####  
    //             #####  
    //  #         ######  
    //  ###      #####    
    //  ###      #####    
    //  #############     
    //  ############      
    //    ########        
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x1F,
    0xFC,
    0x00,
    0x1F,
    0xFC,
    0x00,
    0x7F,
    0xFC,
    0x00,
    0x38,
    0x3E,
    0x00,
    0x10,
    0x1E,
    0x00,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x0F,
    0xF0,
    0x00,
    0x0F,
    0xF0,
    0x00,
    0x0F,
    0xFC,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x40,
    0x1F,
    0x80,
    0x70,
    0x3E,
    0x00,
    0x70,
    0x3E,
    0x00,
    0x7F,
    0xFC,
    0x00,
    0x7F,
    0xF8,
    0x00,
    0x1F,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,

    // '4'
    //                     
    //                     
    //                     
    //                     
    //                     
    //                     
    //                     
    //                     
    //                     
    //           ####      
    //           ####      
    //           ####      
    //          #####      
    //          #####      
    //         ######      
    //         ## ###      
    //        ### ###      
    //        ### ###      
    //      ####  ###      
    //      ####  ###      
    //     ####   ###      
    //     ####   ###      
    //    ####    ###      
    //    ####    ###      
    //    ####    ###      
    //   ###      ###      
    //  ####      ###      
    //  ###       ###      
    //  #################  
    //  #################  
    //  #################  
    //            ###      
    //            ###      
    //            ###      
    //            ###      
    //            ###      
    //            ###      
    //            ###      
    //                     
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0xFC,
    0x00,
    0x00,
    0xDC,
    0x00,
    0x01,
    0xDC,
    0x00,
    0x01,
    0xDC,
    0x00,
    0x07,
    0x9C,
    0x00,
    0x07,
    0x9C,
    0x00,
    0x0F,
    0x1C,
    0x00,
    0x0F,
    0x1C,
    0x00,
    0x1E,
    0x1C,
    0x00,
    0x1E,
    0x1C,
    0x00,
    0x1E,
    0x1C,
    0x00,
    0x38,
    0x1C,
    0x00,
    0x78,
    0x1C,
    0x00,
    0x70,
    0x1C,
    0x00,
    0x7F,
    0xFF,
    0xC0,
    0x7F,
    0xFF,
    0xC0,
    0x7F,
    0xFF,
    0xC0,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,

    // '5'
    //                   
    //                   
    //                   
    //                   
    //                   
    //                   
    //                   
    //                   
    //                   
    //   ############    
    //   ############    
    //   ############    
    //   ############    
    //   ####            
    //   ####            
    //   ####            
    //  #####            
    //  #####            
    //  #####            
    //  #####            
    //  ##########       
    //  ############     
    //  #############    
    //  #############    
    //   #      #####    
    //           ######  
    //            #####  
    //            #####  
    //            #####  
    //            #####  
    //            #####  
    //            #####  
    //  #        ####    
    //  ##      #####    
    //  ##      #####    
    //  ############     
    //  ###########      
    //   ########        
    //                   
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3F,
    0xFC,
    0x00,
    0x3F,
    0xFC,
    0x00,
    0x3F,
    0xFC,
    0x00,
    0x3F,
    0xFC,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0x7C,
    0x00,
    0x00,
    0x7F,
    0xE0,
    0x00,
    0x7F,
    0xF8,
    0x00,
    0x7F,
    0xFC,
    0x00,
    0x7F,
    0xFC,
    0x00,
    0x20,
    0x7C,
    0x00,
    0x00,
    0x3F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x40,
    0x3C,
    0x00,
    0x60,
    0x7C,
    0x00,
    0x60,
    0x7C,
    0x00,
    0x7F,
    0xF8,
    0x00,
    0x7F,
    0xF0,
    0x00,
    0x3F,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // '6'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //          ######    
    //        ########    
    //        ########    
    //      ##########    
    //     ######         
    //    #####           
    //    ####            
    //    ####            
    //   #####            
    //   ###              
    //   ###   #####      
    //   ###  #######     
    //   #############    
    //   ######   ####    
    //   ######   ####    
    //  ######     #####  
    //  ######     #####  
    //  ####        ####  
    //  ####        ####  
    //   ###        ####  
    //   ###        ####  
    //   #####     #####  
    //   #####     #####  
    //    ####     #####  
    //    #####   ####    
    //    #####   ####    
    //     ###########    
    //      #########     
    //        #####       
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x7E,
    0x00,
    0x01,
    0xFE,
    0x00,
    0x01,
    0xFE,
    0x00,
    0x07,
    0xFE,
    0x00,
    0x0F,
    0xC0,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x00,
    0x38,
    0x00,
    0x00,
    0x38,
    0xF8,
    0x00,
    0x39,
    0xFC,
    0x00,
    0x3F,
    0xFE,
    0x00,
    0x3F,
    0x1E,
    0x00,
    0x3F,
    0x1E,
    0x00,
    0x7E,
    0x0F,
    0x80,
    0x7E,
    0x0F,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x38,
    0x07,
    0x80,
    0x38,
    0x07,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x1E,
    0x0F,
    0x80,
    0x1F,
    0x1E,
    0x00,
    0x1F,
    0x1E,
    0x00,
    0x0F,
    0xFE,
    0x00,
    0x07,
    0xFC,
    0x00,
    0x01,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,

    // '7'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //  ################  
    //  ################  
    //  ################  
    //  ################  
    //             #####  
    //             #####  
    //             ###    
    //            ####    
    //            ####    
    //            ###     
    //           ####     
    //           ####     
    //           ###      
    //          ####      
    //          ####      
    //          ####      
    //          ###       
    //         ####       
    //         ####       
    //        ####        
    //        ####        
    //        ####        
    //      #####         
    //      #####         
    //      #####         
    //      #####         
    //     #####          
    //     #####          
    //    ######          
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x7F,
    0xFF,
    0x80,
    0x7F,
    0xFF,
    0x80,
    0x7F,
    0xFF,
    0x80,
    0x7F,
    0xFF,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x00,
    0x38,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0x70,
    0x00,
    0x00,
    0xF0,
    0x00,
    0x00,
    0xF0,
    0x00,
    0x01,
    0xE0,
    0x00,
    0x01,
    0xE0,
    0x00,
    0x01,
    0xE0,
    0x00,
    0x07,
    0xC0,
    0x00,
    0x07,
    0xC0,
    0x00,
    0x07,
    0xC0,
    0x00,
    0x07,
    0xC0,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x1F,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,

    // '8'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //      #######       
    //     ##########     
    //     ##########     
    //    ############    
    //   ######   ####    
    //   #####     #####  
    //   #####     #####  
    //   ###       #####  
    //   #####     #####  
    //   #####     ###    
    //    #####   ####    
    //    ###### ####     
    //     #########      
    //      #######       
    //      #######       
    //     #########      
    //    #####  ####     
    //   #####    ####    
    //   ###       #####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //  ####        ####  
    //   ###       #####  
    //   #####    ######  
    //   #####    ######  
    //   #############    
    //    ###########     
    //      #######       
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x0F,
    0xFC,
    0x00,
    0x0F,
    0xFC,
    0x00,
    0x1F,
    0xFE,
    0x00,
    0x3F,
    0x1E,
    0x00,
    0x3E,
    0x0F,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x3E,
    0x0E,
    0x00,
    0x1F,
    0x1E,
    0x00,
    0x1F,
    0xBC,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x1F,
    0x3C,
    0x00,
    0x3E,
    0x1E,
    0x00,
    0x38,
    0x0F,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x78,
    0x07,
    0x80,
    0x38,
    0x0F,
    0x80,
    0x3E,
    0x1F,
    0x80,
    0x3E,
    0x1F,
    0x80,
    0x3F,
    0xFE,
    0x00,
    0x1F,
    0xFC,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,

    // '9'
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //                    
    //      #######       
    //     #########      
    //     #########      
    //    ###########     
    //   ######   ####    
    //   #####    ####    
    //   ###       ###    
    //  ####       #####  
    //  ####       #####  
    //  ####       #####  
    //  ####       #####  
    //  ####       #####  
    //   #####     #####  
    //   #####    ######  
    //   #####    ######  
    //    ######### ####  
    //    ######### ####  
    //      #####  #####  
    //             #####  
    //             #####  
    //             ###    
    //            ####    
    //            ####    
    //           ####     
    //   #      #####     
    //   #      #####     
    //    ##########      
    //    #########       
    //    #######         
    //                    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x07,
    0xF0,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x0F,
    0xF8,
    0x00,
    0x1F,
    0xFC,
    0x00,
    0x3F,
    0x1E,
    0x00,
    0x3E,
    0x1E,
    0x00,
    0x38,
    0x0E,
    0x00,
    0x78,
    0x0F,
    0x80,
    0x78,
    0x0F,
    0x80,
    0x78,
    0x0F,
    0x80,
    0x78,
    0x0F,
    0x80,
    0x78,
    0x0F,
    0x80,
    0x3E,
    0x0F,
    0x80,
    0x3E,
    0x1F,
    0x80,
    0x3E,
    0x1F,
    0x80,
    0x1F,
    0xF7,
    0x80,
    0x1F,
    0xF7,
    0x80,
    0x07,
    0xCF,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0F,
    0x80,
    0x00,
    0x0E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x1E,
    0x00,
    0x00,
    0x3C,
    0x00,
    0x20,
    0x7C,
    0x00,
    0x20,
    0x7C,
    0x00,
    0x1F,
    0xF8,
    0x00,
    0x1F,
    0xF0,
    0x00,
    0x1F,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // ':'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //  ####  
    // #####  
    // ###### 
    // #####  
    //  ####  
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //  ####  
    // #####  
    // #####  
    // ###### 
    // #####  
    //  ####  
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xF8,
    0xFC,
    0xF8,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xF8,
    0xF8,
    0xFC,
    0xF8,
    0x78,
    0x00
};

// normal font character widths
const std::array<uint8_t, normal_font_len> normal_font_char_widths = {
    8, // '0'
    6, // '1'
    8, // '2'
    8, // '3'
    9, // '4'
    8, // '5'
    8, // '6'
    8, // '7'
    8, // '8'
    8, // '9'
    3, // ':'
    5, // ' '
    3, // '''
    6, // '-'
    10, // 'A'
    9, // 'B'
    9, // 'D'
    7, // 'F'
    9, // 'G'
    3, // 'J'
    12, // 'M'
    10, // 'N'
    10, // 'O'
    8, // 'P'
    10, // 'Q'
    9, // 'R'
    7, // 'S'
    9, // 'T'
    10, // 'V'
    7, // 'a'
    8, // 'b'
    7, // 'c'
    8, // 'd'
    8, // 'e'
    7, // 'f'
    8, // 'g'
    8, // 'h'
    3, // 'i'
    4, // 'j'
    3, // 'l'
    12, // 'm'
    8, // 'n'
    8, // 'o'
    8, // 'p'
    8, // 'q'
    6, // 'r'
    6, // 's'
    6, // 't'
    8, // 'u'
    9, // 'v'
    8, // 'x'
    9, // 'y'
    7, // 'z'
    7, // 'à'
    7, // 'â'
    8, // 'è'
    8, // 'é'
    8, // 'ê'
    6, // 'î'
    4, // 'ï'
    8, // 'ô'
    8, // 'û'
    13, // 'œ'
    10, // '🔔' (custom bell bitmap)
};

// normal font character begin positions
const std::array<uint16_t, normal_font_len> normal_font_char_begin = {
    0, // '0'
    24, // '1'
    48, // '2'
    72, // '3'
    96, // '4'
    144, // '5'
    168, // '6'
    192, // '7'
    216, // '8'
    240, // '9'
    264, // ':'
    288, // ' '
    312, // '''
    336, // '-'
    360, // 'A'
    408, // 'B'
    456, // 'D'
    504, // 'F'
    528, // 'G'
    576, // 'J'
    600, // 'M'
    648, // 'N'
    696, // 'O'
    744, // 'P'
    768, // 'Q'
    816, // 'R'
    864, // 'S'
    888, // 'T'
    936, // 'V'
    984, // 'a'
    1008, // 'b'
    1032, // 'c'
    1056, // 'd'
    1080, // 'e'
    1104, // 'f'
    1128, // 'g'
    1152, // 'h'
    1176, // 'i'
    1200, // 'j'
    1224, // 'l'
    1248, // 'm'
    1296, // 'n'
    1320, // 'o'
    1344, // 'p'
    1368, // 'q'
    1392, // 'r'
    1416, // 's'
    1440, // 't'
    1464, // 'u'
    1488, // 'v'
    1536, // 'x'
    1560, // 'y'
    1608, // 'z'
    1632, // 'à'
    1656, // 'â'
    1680, // 'è'
    1704, // 'é'
    1728, // 'ê'
    1752, // 'î'
    1776, // 'ï'
    1800, // 'ô'
    1824, // 'û'
    1848, // 'œ'
    1896, // '🔔' (custom bell bitmap)
};

// normal font content (bitmap data, packed)
const std::array<uint8_t, 1944> normal_font_content = {
    // '0'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    //  #####  
    // ##  ##  
    // ##   #  
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   #  
    // ##  ##  
    //  #####  
    //  ####   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x7C,
    0xCC,
    0xC4,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC4,
    0xCC,
    0x7C,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,

    // '1'
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //    ## 
    //   ### 
    //  #### 
    // ## ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //    ## 
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x18,
    0x38,
    0x78,
    0xD8,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,

    // '2'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    // ######  
    // #   ##  
    //     ##  
    //     ##  
    //     ##  
    //    ##   
    //    ##   
    //   ##    
    //  ##     
    //  ##     
    // ####### 
    // ####### 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xFC,
    0x8C,
    0x0C,
    0x0C,
    0x0C,
    0x18,
    0x18,
    0x30,
    0x60,
    0x60,
    0xFE,
    0xFE,
    0x00,
    0x00,
    0x00,
    0x00,

    // '3'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    // ######  
    // #   ##  
    //     ##  
    //     ##  
    //  ####   
    //  ####   
    //     ##  
    //      #  
    //      ## 
    //     ##  
    // ######  
    // #####   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xFC,
    0x8C,
    0x0C,
    0x0C,
    0x78,
    0x78,
    0x0C,
    0x04,
    0x06,
    0x0C,
    0xFC,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,

    // '4'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //      ##  
    //     ###  
    //     ###  
    //    # ##  
    //   ## ##  
    //   #  ##  
    //  ##  ##  
    //  #   ##  
    // ######## 
    // ######## 
    //      ##  
    //      ##  
    //      ##  
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x06,
    0x00,
    0x0E,
    0x00,
    0x0E,
    0x00,
    0x16,
    0x00,
    0x36,
    0x00,
    0x26,
    0x00,
    0x66,
    0x00,
    0x46,
    0x00,
    0xFF,
    0x00,
    0xFF,
    0x00,
    0x06,
    0x00,
    0x06,
    0x00,
    0x06,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // '5'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ######  
    // ######  
    // ##      
    // ##      
    // ##      
    // #####   
    // ######  
    //     ##  
    //      ## 
    //      ## 
    //     ##  
    // ######  
    // #####   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0xFC,
    0xC0,
    0xC0,
    0xC0,
    0xF8,
    0xFC,
    0x0C,
    0x06,
    0x06,
    0x0C,
    0xFC,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,

    // '6'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //   ####  
    //  #####  
    //  #      
    // ##      
    // ## #    
    // ######  
    // ##  ##  
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   #  
    //  #####  
    //   ###   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3C,
    0x7C,
    0x40,
    0xC0,
    0xD0,
    0xFC,
    0xCC,
    0xC6,
    0xC6,
    0xC6,
    0xC4,
    0x7C,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,

    // '7'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ####### 
    // ####### 
    //     ##  
    //     ##  
    //     ##  
    //    ##   
    //    ##   
    //    ##   
    //   ##    
    //   ##    
    //   ##    
    //  ##     
    //  ##     
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFE,
    0xFE,
    0x0C,
    0x0C,
    0x0C,
    0x18,
    0x18,
    0x18,
    0x30,
    0x30,
    0x30,
    0x60,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,

    // '8'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    // ######  
    // ##   #  
    // ##   #  
    // ##  ##  
    //  ####   
    //  ####   
    // ##  ##  
    // ##   ## 
    // #    ## 
    // ##   ## 
    // ######  
    //  ####   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xFC,
    0xC4,
    0xC4,
    0xCC,
    0x78,
    0x78,
    0xCC,
    0xC6,
    0x86,
    0xC6,
    0xFC,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,

    // '9'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    // ######  
    // ##  ##  
    // ##   #  
    // #    ## 
    // ##  ### 
    // ####### 
    //  ### #  
    //      #  
    //     ##  
    //     ##  
    // #####   
    // ####    
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xFC,
    0xCC,
    0xC4,
    0x86,
    0xCE,
    0xFE,
    0x74,
    0x04,
    0x0C,
    0x0C,
    0xF8,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,

    // ':'
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    // ## 
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    // ## 
    //    
    //    
    //    
    //    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // ' '
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // '''
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // '-'
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    // ##### 
    // ##### 
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xF8,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'A'
    //           
    //           
    //           
    //           
    //           
    //           
    //           
    //    ###    
    //    ###    
    //    # #    
    //    # ##   
    //   ## ##   
    //   ## ##   
    //   #   #   
    //  #######  
    //  #######  
    //  ##   ##  
    //  ##    ## 
    // ##     ## 
    // ##     ## 
    //           
    //           
    //           
    //           
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x14,
    0x00,
    0x16,
    0x00,
    0x36,
    0x00,
    0x36,
    0x00,
    0x22,
    0x00,
    0x7F,
    0x00,
    0x7F,
    0x00,
    0x63,
    0x00,
    0x61,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'B'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ######   
    // #######  
    // ##   ##  
    // ##   ##  
    // ##   ##  
    // #######  
    // ######   
    // ##   ##  
    // ##    ## 
    // ##    ## 
    // ##   ##  
    // #######  
    // ######   
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0x00,
    0xFE,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xFE,
    0x00,
    0xFC,
    0x00,
    0xC6,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC6,
    0x00,
    0xFE,
    0x00,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'D'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ######   
    // #######  
    // ##   ### 
    // ##    ## 
    // ##    ## 
    // ##    ## 
    // ##    ## 
    // ##    ## 
    // ##    ## 
    // ##    ## 
    // ##   ### 
    // #######  
    // ######   
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0x00,
    0xFE,
    0x00,
    0xC7,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC3,
    0x00,
    0xC7,
    0x00,
    0xFE,
    0x00,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'F'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    // ###### 
    // ###### 
    // ##     
    // ##     
    // ##     
    // ##     
    // ###### 
    // ###### 
    // ##     
    // ##     
    // ##     
    // ##     
    // ##     
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0xFC,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xFC,
    0xFC,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'G'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //    ##### 
    //  ####### 
    //  ##      
    // ##       
    // ##       
    // ##       
    // ##   ### 
    // ##   ### 
    // ##     # 
    // ##     # 
    //  ##    # 
    //  ####### 
    //    ##### 
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x7F,
    0x00,
    0x60,
    0x00,
    0xC0,
    0x00,
    0xC0,
    0x00,
    0xC0,
    0x00,
    0xC7,
    0x00,
    0xC7,
    0x00,
    0xC1,
    0x00,
    0xC1,
    0x00,
    0x61,
    0x00,
    0x7F,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'J'
    //    
    //    
    //    
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    //    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,

    // 'M'
    //             
    //             
    //             
    //             
    //             
    //             
    //             
    // ###      ## 
    // ###     ### 
    // ####    ### 
    // ####    # # 
    // ## #    # # 
    // ## #   ## # 
    // ## ##  #  # 
    // ## ##  #  # 
    // ##  # ##  # 
    // ##  ####  # 
    // ##  ###   # 
    // ##   ##   # 
    // ##   ##   # 
    //             
    //             
    //             
    //             
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xE0,
    0x60,
    0xE0,
    0xE0,
    0xF0,
    0xE0,
    0xF0,
    0xA0,
    0xD0,
    0xA0,
    0xD1,
    0xA0,
    0xD9,
    0x20,
    0xD9,
    0x20,
    0xCB,
    0x20,
    0xCF,
    0x20,
    0xCE,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'N'
    //           
    //           
    //           
    //           
    //           
    //           
    //           
    // ###    ## 
    // ###    ## 
    // ####   ## 
    // ####   ## 
    // ## ##  ## 
    // ## ##  ## 
    // ##  ## ## 
    // ##  ## ## 
    // ##   # ## 
    // ##   #### 
    // ##   #### 
    // ##    ### 
    // ##    ### 
    //           
    //           
    //           
    //           
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xE1,
    0x80,
    0xE1,
    0x80,
    0xF1,
    0x80,
    0xF1,
    0x80,
    0xD9,
    0x80,
    0xD9,
    0x80,
    0xCD,
    0x80,
    0xCD,
    0x80,
    0xC5,
    0x80,
    0xC7,
    0x80,
    0xC7,
    0x80,
    0xC3,
    0x80,
    0xC3,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'O'
    //           
    //           
    //           
    //           
    //           
    //           
    //           
    //   #####   
    //  #######  
    //  ##   ##  
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    //  ##   ##  
    //  #######  
    //   #####   
    //           
    //           
    //           
    //           
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x7F,
    0x00,
    0x63,
    0x00,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0x63,
    0x00,
    0x7F,
    0x00,
    0x3E,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'P'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ######  
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ######  
    // #####   
    // ##      
    // ##      
    // ##      
    // ##      
    // ##      
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFC,
    0xF8,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'Q'
    //           
    //           
    //           
    //           
    //           
    //           
    //           
    //   #####   
    //  #######  
    //  ##   ##  
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    // ##     ## 
    //  ##   ##  
    //  #######  
    //   #####   
    //      ##   
    //       ##  
    //       ### 
    //           
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3E,
    0x00,
    0x7F,
    0x00,
    0x63,
    0x00,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0xC1,
    0x80,
    0x63,
    0x00,
    0x7F,
    0x00,
    0x3E,
    0x00,
    0x06,
    0x00,
    0x03,
    0x00,
    0x03,
    0x80,
    0x00,
    0x00,

    // 'R'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ######   
    // #######  
    // ##   ##  
    // ##   ##  
    // ##   ##  
    // ##   ##  
    // ######   
    // #####    
    // ##  ##   
    // ##  ##   
    // ##   ##  
    // ##   ##  
    // ##    ## 
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFC,
    0x00,
    0xFE,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xFC,
    0x00,
    0xF8,
    0x00,
    0xCC,
    0x00,
    0xCC,
    0x00,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0xC3,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'S'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //  ##### 
    // ###### 
    // ##     
    // ##     
    // ##     
    // ###    
    //  ####  
    //    ### 
    //     ## 
    //     ## 
    //     ## 
    // ###### 
    // #####  
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x7C,
    0xFC,
    0xC0,
    0xC0,
    0xC0,
    0xE0,
    0x78,
    0x1C,
    0x0C,
    0x0C,
    0x0C,
    0xFC,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'T'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ######## 
    // ######## 
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //    ##    
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFF,
    0x00,
    0xFF,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'V'
    //           
    //           
    //           
    //           
    //           
    //           
    //           
    // ##     ## 
    // ##     #  
    //  ##   ##  
    //  ##   ##  
    //  ##   ##  
    //  ##   #   
    //   #  ##   
    //   ## ##   
    //   ## ##   
    //   ## #    
    //    ###    
    //    ###    
    //    ###    
    //           
    //           
    //           
    //           
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC1,
    0x80,
    0xC1,
    0x00,
    0x63,
    0x00,
    0x63,
    0x00,
    0x63,
    0x00,
    0x62,
    0x00,
    0x26,
    0x00,
    0x36,
    0x00,
    0x36,
    0x00,
    0x34,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x1C,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'a'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    // #####  
    //  ##### 
    //     ## 
    //     ## 
    //  ##### 
    // ###### 
    // ##  ## 
    // #   ## 
    // #### # 
    //  ### # 
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xF8,
    0x7C,
    0x0C,
    0x0C,
    0x7C,
    0xFC,
    0xCC,
    0x8C,
    0xF4,
    0x74,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'b'
    //         
    //         
    //         
    //         
    //         
    //         
    // ##      
    // ##      
    // ##      
    // ##      
    // ## ###  
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ####### 
    // ## ###  
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xDC,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFE,
    0xDC,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'c'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //   #### 
    //  ####  
    // ##     
    // ##     
    // ##     
    // ##     
    // ##     
    // ##     
    // #####  
    //  ####  
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3C,
    0x78,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xF8,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'd'
    //         
    //         
    //         
    //         
    //         
    //         
    //      ## 
    //      ## 
    //      ## 
    //      ## 
    //  ### ## 
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ####### 
    //  ### ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x06,
    0x06,
    0x06,
    0x06,
    0x76,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFE,
    0x76,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'e'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    //  #####  
    // ##   #  
    // ##   #  
    // ####### 
    // ####### 
    // ##      
    // ##      
    //  #####  
    //   ####  
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x7C,
    0xC4,
    0xC4,
    0xFE,
    0xFE,
    0xC0,
    0xC0,
    0x7C,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'f'
    //        
    //        
    //        
    //        
    //        
    //        
    //   #### 
    //   ###  
    //  ##    
    //  ##    
    // #####  
    // #####  
    //  ##    
    //  ##    
    //  ##    
    //  ##    
    //  ##    
    //  ##    
    //  ##    
    //  ##    
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3C,
    0x38,
    0x60,
    0x60,
    0xF8,
    0xF8,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'g'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ### ## 
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ####### 
    //  ### ## 
    //      ## 
    //      ## 
    // ######  
    // #####   
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x76,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFE,
    0x76,
    0x06,
    0x06,
    0xFC,
    0xF8,

    // 'h'
    //         
    //         
    //         
    //         
    //         
    //         
    // ##      
    // ##      
    // ##      
    // ##      
    // ## ###  
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xDC,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'i'
    //    
    //    
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    //    
    //    
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    //    
    //    
    //    
    //    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'j'
    //     
    //     
    //     
    //     
    //     
    //     
    //  ## 
    //  ## 
    //     
    //     
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    // ### 
    // ##  
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0x60,
    0x00,
    0x00,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0xE0,
    0xC0,

    // 'l'
    //    
    //    
    //    
    //    
    //    
    //    
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    // ## 
    //    
    //    
    //    
    //    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'm'
    //             
    //             
    //             
    //             
    //             
    //             
    //             
    //             
    //             
    //             
    // ## ### ###  
    // ########### 
    // ##   ##  ## 
    // ##   ##   # 
    // ##   ##   # 
    // ##   ##   # 
    // ##   ##   # 
    // ##   ##   # 
    // ##   ##   # 
    // ##   ##   # 
    //             
    //             
    //             
    //             
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xDD,
    0xC0,
    0xFF,
    0xE0,
    0xC6,
    0x60,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0xC6,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'n'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ## ###  
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xDC,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'o'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ####   
    //  #####  
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    //  #####  
    //   ###   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x7C,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0x7C,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'p'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ## ###  
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ####### 
    // ## ###  
    // ##      
    // ##      
    // ##      
    // ##      
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xDC,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFE,
    0xDC,
    0xC0,
    0xC0,
    0xC0,
    0xC0,

    // 'q'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //  ### ## 
    // ####### 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ####### 
    //  ### ## 
    //      ## 
    //      ## 
    //      ## 
    //      ## 
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x76,
    0xFE,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xFE,
    0x76,
    0x06,
    0x06,
    0x06,
    0x06,

    // 'r'
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    // ## ## 
    // ##### 
    // ##    
    // ##    
    // ##    
    // ##    
    // ##    
    // ##    
    // ##    
    // ##    
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xD8,
    0xF8,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 's'
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //  #### 
    // ##### 
    // #     
    // ##    
    // ###   
    //   ### 
    //    ## 
    //    ## 
    // ##### 
    // ####  
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0xF8,
    0x80,
    0xC0,
    0xE0,
    0x38,
    0x18,
    0x18,
    0xF8,
    0xF0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 't'
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //       
    //   #   
    //   #   
    // ##### 
    // ##### 
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  #### 
    //   ### 
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x20,
    0x20,
    0xF8,
    0xF8,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x78,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'u'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ### ### 
    //  ### ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xEE,
    0x76,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'v'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ##    ## 
    // ##   ##  
    //  ##  ##  
    //  ##  ##  
    //  ##  #   
    //   # ##   
    //   # ##   
    //   ###    
    //   ###    
    //    ##    
    //          
    //          
    //          
    //          
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC3,
    0x00,
    0xC6,
    0x00,
    0x66,
    0x00,
    0x66,
    0x00,
    0x64,
    0x00,
    0x2C,
    0x00,
    0x2C,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'x'
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    //         
    // ###  ## 
    //  ##  ## 
    //   # ##  
    //   ####  
    //    ##   
    //   ###   
    //   ####  
    //  ## ##  
    //  ##  ## 
    // ##   ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xE6,
    0x66,
    0x2C,
    0x3C,
    0x18,
    0x38,
    0x3C,
    0x6C,
    0x66,
    0xC6,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'y'
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    //          
    // ##    ## 
    // ##   ##  
    //  ##  ##  
    //  ##  ##  
    //  ##  #   
    //   # ##   
    //   ####   
    //   ###    
    //    ##    
    //    ##    
    //    ##    
    //   ##     
    // ####     
    // ###      
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xC3,
    0x00,
    0xC6,
    0x00,
    0x66,
    0x00,
    0x66,
    0x00,
    0x64,
    0x00,
    0x2C,
    0x00,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x18,
    0x00,
    0x30,
    0x00,
    0xF0,
    0x00,
    0xE0,
    0x00,

    // 'z'
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //        
    //  ##### 
    //  ##### 
    //    ##  
    //    ##  
    //   ##   
    //   ##   
    //   #    
    //  ##    
    //  ##### 
    // ###### 
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x7C,
    0x7C,
    0x18,
    0x18,
    0x30,
    0x30,
    0x20,
    0x60,
    0x7C,
    0xFC,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'à'
    //        
    //        
    //        
    //        
    //        
    //        
    //  ##    
    //   ##   
    //    #   
    //        
    // #####  
    //  ##### 
    //     ## 
    //     ## 
    //  ##### 
    // ###### 
    // ##  ## 
    // #   ## 
    // #### # 
    //  ### # 
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0x30,
    0x10,
    0x00,
    0xF8,
    0x7C,
    0x0C,
    0x0C,
    0x7C,
    0xFC,
    0xCC,
    0x8C,
    0xF4,
    0x74,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'â'
    //        
    //        
    //        
    //        
    //        
    //        
    //   ##   
    //  ####  
    //  #  ## 
    //        
    // #####  
    //  ##### 
    //     ## 
    //     ## 
    //  ##### 
    // ###### 
    // ##  ## 
    // #   ## 
    // #### # 
    //  ### # 
    //        
    //        
    //        
    //        
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x78,
    0x4C,
    0x00,
    0xF8,
    0x7C,
    0x0C,
    0x0C,
    0x7C,
    0xFC,
    0xCC,
    0x8C,
    0xF4,
    0x74,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'è'
    //         
    //         
    //         
    //         
    //         
    //         
    //  ##     
    //   ##    
    //    #    
    //         
    //  ####   
    //  #####  
    // ##   #  
    // ##   #  
    // ####### 
    // ####### 
    // ##      
    // ##      
    //  #####  
    //   ####  
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0x30,
    0x10,
    0x00,
    0x78,
    0x7C,
    0xC4,
    0xC4,
    0xFE,
    0xFE,
    0xC0,
    0xC0,
    0x7C,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'é'
    //         
    //         
    //         
    //         
    //         
    //         
    //     ##  
    //    ##   
    //   ##    
    //         
    //  ####   
    //  #####  
    // ##   #  
    // ##   #  
    // ####### 
    // ####### 
    // ##      
    // ##      
    //  #####  
    //   ####  
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x0C,
    0x18,
    0x30,
    0x00,
    0x78,
    0x7C,
    0xC4,
    0xC4,
    0xFE,
    0xFE,
    0xC0,
    0xC0,
    0x7C,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'ê'
    //         
    //         
    //         
    //         
    //         
    //         
    //   ##    
    //  ####   
    //  #  ##  
    //         
    //  ####   
    //  #####  
    // ##   #  
    // ##   #  
    // ####### 
    // ####### 
    // ##      
    // ##      
    //  #####  
    //   ####  
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x78,
    0x4C,
    0x00,
    0x78,
    0x7C,
    0xC4,
    0xC4,
    0xFE,
    0xFE,
    0xC0,
    0xC0,
    0x7C,
    0x3C,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'î'
    //       
    //       
    //       
    //       
    //       
    //       
    //  ##   
    // ####  
    // #  ## 
    //       
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //  ##   
    //       
    //       
    //       
    //       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0xF0,
    0x98,
    0x00,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'ï'
    //     
    //     
    //     
    //     
    //     
    //     
    //     
    //   # 
    //   # 
    //     
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    // ##  
    //     
    //     
    //     
    //     
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x20,
    0x20,
    0x00,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0xC0,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'ô'
    //         
    //         
    //         
    //         
    //         
    //         
    //   ##    
    //   # #   
    //  #  ##  
    //         
    //  ####   
    //  #####  
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    //  #####  
    //   ###   
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x28,
    0x4C,
    0x00,
    0x78,
    0x7C,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0x7C,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'û'
    //         
    //         
    //         
    //         
    //         
    //         
    //   ###   
    //   # #   
    //  #   #  
    //         
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ##   ## 
    // ### ### 
    //  ### ## 
    //         
    //         
    //         
    //         
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x28,
    0x44,
    0x00,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xC6,
    0xEE,
    0x76,
    0x00,
    0x00,
    0x00,
    0x00,

    // 'œ'
    //              
    //              
    //              
    //              
    //              
    //              
    //              
    //              
    //              
    //              
    //  ####  ###   
    //  ##########  
    // ##   ##   ## 
    // ##   ##   ## 
    // ##   ####### 
    // ##   ####### 
    // ##   ##      
    // ##   ##      
    //  ##########  
    //   ###  ####  
    //              
    //              
    //              
    //              
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x79,
    0xC0,
    0x7F,
    0xE0,
    0xC6,
    0x30,
    0xC6,
    0x30,
    0xC7,
    0xF0,
    0xC7,
    0xF0,
    0xC6,
    0x00,
    0xC6,
    0x00,
    0x7F,
    0xE0,
    0x39,
    0xE0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    // '🔔' (custom bell bitmap)
    //    ###   
    //   #####  
    //  ####### 
    //  ####### 
    // #########
    // #########
    // #########
    // #########
    // #########
    // #########
    // #########
    // #########
    // #########
    // #########
    //  ####### 
    //          
    //    ###   
    //    ###   
    //          
    //          
    //          
    //          
    //          
    //          
    0x1C,
    0x00,
    0x7C,
    0x40,
    0xFC,
    0xC0,
    0xFB,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFF,
    0xC0,
    0xFD,
    0xC0,
    0xF0,
    0x00,
    0x01,
    0xC0,
    0x03,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};

} // namespace rr::ui
