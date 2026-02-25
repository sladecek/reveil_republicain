#include "drawing_objects.h"

namespace rr::ui {

// Fragment content (character indices)
const std::array<uint8_t, fragment_content_size> fragment_content = {
    // nr: "0"
    3,

    // "1"
    4,

    // "2"
    5,

    // "3"
    6,

    // "4"
    7,

    // "5"
    8,

    // "6"
    9,

    // "7"
    10,

    // "8"
    11,

    // "9"
    12,

    // colon: ":"
    13,

    // bell: "🔔"
    61,

    // run: "run"
    43, 46, 39,

    // stop: "stop"
    44, 45, 40, 41,

    // alarm: "alarm"
    27, 37, 27, 43, 38,

    // hour: "hour"
    34, 40, 46, 43,

    // minute: "minute"
    38, 35, 39, 46, 45, 31,

    // set: "set"
    44, 31, 45,

    // day: "day"
    30, 27, 49,

    // month: "month"
    38, 40, 39, 45, 34,

    // year: "year"
    49, 31, 27, 43,

    // annee: "année"
    27, 39, 39, 54, 31,

    // on_off: "on"
    40, 39,

    // "off"
    40, 32, 32,

    // months: "Vendémiaire"
    26, 31, 39, 30, 54, 38, 35, 27, 35, 43, 31,

    // "Brumaire"
    14, 43, 46, 38, 27, 35, 43, 31,

    // "Frimaire"
    16, 43, 35, 38, 27, 35, 43, 31,

    // "Nivôse"
    19, 35, 47, 58, 44, 31,

    // "Pluviôse"
    21, 37, 46, 47, 35, 58, 44, 31,

    // "Ventôse"
    26, 31, 39, 45, 58, 44, 31,

    // "Germinal"
    17, 31, 43, 38, 35, 39, 27, 37,

    // "Floréal"
    16, 37, 40, 43, 54, 27, 37,

    // "Prairial"
    21, 43, 27, 35, 43, 35, 27, 37,

    // "Messidor"
    18, 31, 44, 44, 35, 30, 40, 43,

    // "Thermidor"
    25, 34, 31, 43, 38, 35, 30, 40, 43,

    // "Fructidor"
    16, 43, 46, 29, 45, 35, 30, 40, 43,

    // days: "Primidi"
    21, 43, 35, 38, 35, 30, 35,

    // "Duodi"
    15, 46, 40, 30, 35,

    // "Tridi"
    25, 43, 35, 30, 35,

    // "Quartidi"
    22, 46, 27, 43, 45, 35, 30, 35,

    // "Quintidi"
    22, 46, 35, 39, 45, 35, 30, 35,

    // "Sextidi"
    24, 31, 48, 45, 35, 30, 35,

    // "Septidi"
    24, 31, 41, 45, 35, 30, 35,

    // "Octidi"
    20, 29, 45, 35, 30, 35,

    // "Nonidi"
    19, 40, 39, 35, 30, 35,

    // "Décadi"
    15, 54, 29, 27, 30, 35,

    // sansculottides: "Fête de la Vertu"
    16, 55, 45, 31, 0, 30, 31, 0, 37, 27, 0, 26, 31, 43, 45, 46,

    // "Fête du Génie"
    16, 55, 45, 31, 0, 30, 46, 0, 17, 54, 39, 35, 31,

    // "Fête du Travail"
    16, 55, 45, 31, 0, 30, 46, 0, 25, 43, 27, 47, 27, 35, 37,

    // "Fête de l'Opinion"
    16, 55, 45, 31, 0, 30, 31, 0, 37, 1, 20, 41, 35, 39, 35, 40, 39,

    // "Fête des Récompenses"
    16, 55, 45, 31, 0, 30, 31, 44, 0, 23, 54, 29, 40, 38, 41, 31, 39, 44, 31, 44,

    // "Fête de la Révolution"
    16, 55, 45, 31, 0, 30, 31, 0, 37, 27, 0, 23, 54, 47, 40, 37, 46, 45, 35, 40, 39,

    // day_of_year: "raisin"
    43, 27, 35, 44, 35, 39,

    // "safran"
    44, 27, 32, 43, 27, 39,

    // "châtaigne"
    29, 34, 52, 45, 27, 35, 33, 39, 31,

    // "colchique"
    29, 40, 37, 29, 34, 35, 42, 46, 31,

    // "cheval"
    29, 34, 31, 47, 27, 37,

    // "balsamine"
    28, 27, 37, 44, 27, 38, 35, 39, 31,

    // "carotte"
    29, 27, 43, 40, 45, 45, 31,

    // "amarante"
    27, 38, 27, 43, 27, 39, 45, 31,

    // "panais"
    41, 27, 39, 27, 35, 44,

    // "cuve"
    29, 46, 47, 31,

    // "pomme de terre"
    41, 40, 38, 38, 31, 0, 30, 31, 0, 45, 31, 43, 43, 31,

    // "immortelle"
    35, 38, 38, 40, 43, 45, 31, 37, 37, 31,

    // "potiron"
    41, 40, 45, 35, 43, 40, 39,

    // "réséda"
    43, 54, 44, 54, 30, 27,

    // "âne"
    52, 39, 31,

    // "belle de nuit"
    28, 31, 37, 37, 31, 0, 30, 31, 0, 39, 46, 35, 45,

    // "citrouille"
    29, 35, 45, 43, 40, 46, 35, 37, 37, 31,

    // "sarrasin"
    44, 27, 43, 43, 27, 44, 35, 39,

    // "tournesol"
    45, 40, 46, 43, 39, 31, 44, 40, 37,

    // "pressoir"
    41, 43, 31, 44, 44, 40, 35, 43,

    // "chanvre"
    29, 34, 27, 39, 47, 43, 31,

    // "pêche"
    41, 55, 29, 34, 31,

    // "navet"
    39, 27, 47, 31, 45,

    // "amaryllis"
    27, 38, 27, 43, 49, 37, 37, 35, 44,

    // "bœuf"
    28, 60, 46, 32,

    // "aubergine"
    27, 46, 28, 31, 43, 33, 35, 39, 31,

    // "piment"
    41, 35, 38, 31, 39, 45,

    // "tomate"
    45, 40, 38, 27, 45, 31,

    // "orge"
    40, 43, 33, 31,

    // "tonneau"
    45, 40, 39, 39, 31, 27, 46,

    // "pomme"
    41, 40, 38, 38, 31,

    // "céleri"
    29, 54, 37, 31, 43, 35,

    // "poire"
    41, 40, 35, 43, 31,

    // "betterave"
    28, 31, 45, 45, 31, 43, 27, 47, 31,

    // "oie"
    40, 35, 31,

    // "héliotrope"
    34, 54, 37, 35, 40, 45, 43, 40, 41, 31,

    // "figue"
    32, 35, 33, 46, 31,

    // "scorsonère"
    44, 29, 40, 43, 44, 40, 39, 53, 43, 31,

    // "alisier"
    27, 37, 35, 44, 35, 31, 43,

    // "charrue"
    29, 34, 27, 43, 43, 46, 31,

    // "salsifis"
    44, 27, 37, 44, 35, 32, 35, 44,

    // "macre"
    38, 27, 29, 43, 31,

    // "topinambour"
    45, 40, 41, 35, 39, 27, 38, 28, 40, 46, 43,

    // "endive"
    31, 39, 30, 35, 47, 31,

    // "dindon"
    30, 35, 39, 30, 40, 39,

    // "chervis"
    29, 34, 31, 43, 47, 35, 44,

    // "cresson"
    29, 43, 31, 44, 44, 40, 39,

    // "dentelaire"
    30, 31, 39, 45, 31, 37, 27, 35, 43, 31,

    // "grenade"
    33, 43, 31, 39, 27, 30, 31,

    // "herse"
    34, 31, 43, 44, 31,

    // "bacchante"
    28, 27, 29, 29, 34, 27, 39, 45, 31,

    // "azerole"
    27, 50, 31, 43, 40, 37, 31,

    // "garance"
    33, 27, 43, 27, 39, 29, 31,

    // "orange"
    40, 43, 27, 39, 33, 31,

    // "faisan"
    32, 27, 35, 44, 27, 39,

    // "pistache"
    41, 35, 44, 45, 27, 29, 34, 31,

    // "macjonc"
    38, 27, 29, 36, 40, 39, 29,

    // "coing"
    29, 40, 35, 39, 33,

    // "cormier"
    29, 40, 43, 38, 35, 31, 43,

    // "rouleau"
    43, 40, 46, 37, 31, 27, 46,

    // "raiponce"
    43, 27, 35, 41, 40, 39, 29, 31,

    // "turneps"
    45, 46, 43, 39, 31, 41, 44,

    // "chicorée"
    29, 34, 35, 29, 40, 43, 54, 31,

    // "nèfle"
    39, 53, 32, 37, 31,

    // "cochon"
    29, 40, 29, 34, 40, 39,

    // "mâche"
    38, 52, 29, 34, 31,

    // "chou-fleur"
    29, 34, 40, 46, 2, 32, 37, 31, 46, 43,

    // "miel"
    38, 35, 31, 37,

    // "génépi"
    33, 54, 39, 54, 41, 35,

    // "pioche"
    41, 35, 40, 29, 34, 31,

    // "cire"
    29, 35, 43, 31,

    // "raifort"
    43, 27, 35, 32, 40, 43, 45,

    // "cèdre"
    29, 53, 30, 43, 31,

    // "sapin"
    44, 27, 41, 35, 39,

    // "chevreuil"
    29, 34, 31, 47, 43, 31, 46, 35, 37,

    // "ajonc"
    27, 36, 40, 39, 29,

    // "cyprès"
    29, 49, 41, 43, 53, 44,

    // "lierre"
    37, 35, 31, 43, 43, 31,

    // "sabine"
    44, 27, 28, 35, 39, 31,

    // "hoye"
    34, 40, 49, 31,

    // "érable sucré"
    54, 43, 27, 28, 37, 31, 0, 44, 46, 29, 43, 54,

    // "bruyère"
    28, 43, 46, 49, 53, 43, 31,

    // "roseau"
    43, 40, 44, 31, 27, 46,

    // "oseille"
    40, 44, 31, 35, 37, 37, 31,

    // "grillon"
    33, 43, 35, 37, 37, 40, 39,

    // "pignon"
    41, 35, 33, 39, 40, 39,

    // "liège"
    37, 35, 53, 33, 31,

    // "truffe"
    45, 43, 46, 32, 32, 31,

    // "olive"
    40, 37, 35, 47, 31,

    // "pelle"
    41, 31, 37, 37, 31,

    // "tourbe"
    45, 40, 46, 43, 28, 31,

    // "houille"
    34, 40, 46, 35, 37, 37, 31,

    // "bitume"
    28, 35, 45, 46, 38, 31,

    // "soufre"
    44, 40, 46, 32, 43, 31,

    // "chien"
    29, 34, 35, 31, 39,

    // "lave"
    37, 27, 47, 31,

    // "terre végétale"
    45, 31, 43, 43, 31, 0, 47, 54, 33, 54, 45, 27, 37, 31,

    // "fumier"
    32, 46, 38, 35, 31, 43,

    // "salpêtre"
    44, 27, 37, 41, 55, 45, 43, 31,

    // "fléau"
    32, 37, 54, 27, 46,

    // "granite"
    33, 43, 27, 39, 35, 45, 31,

    // "argile"
    27, 43, 33, 35, 37, 31,

    // "ardoise"
    27, 43, 30, 40, 35, 44, 31,

    // "grès"
    33, 43, 53, 44,

    // "lapin"
    37, 27, 41, 35, 39,

    // "silex"
    44, 35, 37, 31, 48,

    // "marne"
    38, 27, 43, 39, 31,

    // "pierre à chaux"
    41, 35, 31, 43, 43, 31, 0, 51, 0, 29, 34, 27, 46, 48,

    // "marbre"
    38, 27, 43, 28, 43, 31,

    // "van"
    47, 27, 39,

    // "pierre à plâtre"
    41, 35, 31, 43, 43, 31, 0, 51, 0, 41, 37, 52, 45, 43, 31,

    // "sel"
    44, 31, 37,

    // "fer"
    32, 31, 43,

    // "cuivre"
    29, 46, 35, 47, 43, 31,

    // "chat"
    29, 34, 27, 45,

    // "étain"
    54, 45, 27, 35, 39,

    // "plomb"
    41, 37, 40, 38, 28,

    // "zinc"
    50, 35, 39, 29,

    // "mercure"
    38, 31, 43, 29, 46, 43, 31,

    // "crible"
    29, 43, 35, 28, 37, 31,

    // "lauréole"
    37, 27, 46, 43, 54, 40, 37, 31,

    // "mousse"
    38, 40, 46, 44, 44, 31,

    // "fragon"
    32, 43, 27, 33, 40, 39,

    // "pervenche"
    41, 31, 43, 47, 31, 39, 29, 34, 31,

    // "taureau"
    45, 27, 46, 43, 31, 27, 46,

    // "laurier-tin"
    37, 27, 46, 43, 35, 31, 43, 2, 45, 35, 39,

    // "amatyste"
    27, 38, 27, 45, 49, 44, 45, 31,

    // "mézéréon"
    38, 54, 50, 54, 43, 54, 40, 39,

    // "peuplier"
    41, 31, 46, 41, 37, 35, 31, 43,

    // "coignée"
    29, 40, 35, 33, 39, 54, 31,

    // "ellébore"
    31, 37, 37, 54, 28, 40, 43, 31,

    // "brocoli"
    28, 43, 40, 29, 40, 37, 35,

    // "laurier"
    37, 27, 46, 43, 35, 31, 43,

    // "avelinier"
    27, 47, 31, 37, 35, 39, 35, 31, 43,

    // "vache"
    47, 27, 29, 34, 31,

    // "buis"
    28, 46, 35, 44,

    // "lichén"
    37, 35, 29, 34, 54, 39,

    // "if"
    35, 32,

    // "pulmonaire"
    41, 46, 37, 38, 40, 39, 27, 35, 43, 31,

    // "serpette"
    44, 31, 43, 41, 31, 45, 45, 31,

    // "thlaspi"
    45, 34, 37, 27, 44, 41, 35,

    // "thimelé"
    45, 34, 35, 38, 31, 37, 54,

    // "chiendent"
    29, 34, 35, 31, 39, 30, 31, 39, 45,

    // "traînasse"
    45, 43, 27, 56, 39, 27, 44, 44, 31,

    // "lièvre"
    37, 35, 53, 47, 43, 31,

    // "guède"
    33, 46, 53, 30, 31,

    // "noisetier"
    39, 40, 35, 44, 31, 45, 35, 31, 43,

    // "cyclamen"
    29, 49, 29, 37, 27, 38, 31, 39,

    // "chélidoine"
    29, 34, 54, 37, 35, 30, 40, 35, 39, 31,

    // "traîneau"
    45, 43, 27, 56, 39, 31, 27, 46,

    // "tussilage"
    45, 46, 44, 44, 35, 37, 27, 33, 31,

    // "cornouiller"
    29, 40, 43, 39, 40, 46, 35, 37, 37, 31, 43,

    // "violier"
    47, 35, 40, 37, 35, 31, 43,

    // "troène"
    45, 43, 40, 53, 39, 31,

    // "bouc"
    28, 40, 46, 29,

    // "asaret"
    27, 44, 27, 43, 31, 45,

    // "alaterne"
    27, 37, 27, 45, 31, 43, 39, 31,

    // "violette"
    47, 35, 40, 37, 31, 45, 45, 31,

    // "marceau"
    38, 27, 43, 29, 31, 27, 46,

    // "bêche"
    28, 55, 29, 34, 31,

    // "narcisse"
    39, 27, 43, 29, 35, 44, 44, 31,

    // "orme"
    40, 43, 38, 31,

    // "fumeterre"
    32, 46, 38, 31, 45, 31, 43, 43, 31,

    // "vélar"
    47, 54, 37, 27, 43,

    // "chèvre"
    29, 34, 53, 47, 43, 31,

    // "épinard"
    54, 41, 35, 39, 27, 43, 30,

    // "doronic"
    30, 40, 43, 40, 39, 35, 29,

    // "mouron"
    38, 40, 46, 43, 40, 39,

    // "cerfeuil"
    29, 31, 43, 32, 31, 46, 35, 37,

    // "cordeau"
    29, 40, 43, 30, 31, 27, 46,

    // "mandragore"
    38, 27, 39, 30, 43, 27, 33, 40, 43, 31,

    // "persil"
    41, 31, 43, 44, 35, 37,

    // "cochléaria"
    29, 40, 29, 34, 37, 54, 27, 43, 35, 27,

    // "pâquerette"
    41, 52, 42, 46, 31, 43, 31, 45, 45, 31,

    // "thon"
    45, 34, 40, 39,

    // "pissenlit"
    41, 35, 44, 44, 31, 39, 37, 35, 45,

    // "sylvie"
    44, 49, 37, 47, 35, 31,

    // "capillaire"
    29, 27, 41, 35, 37, 37, 27, 35, 43, 31,

    // "frêne"
    32, 43, 55, 39, 31,

    // "plantoir"
    41, 37, 27, 39, 45, 40, 35, 43,

    // "primevère"
    41, 43, 35, 38, 31, 47, 53, 43, 31,

    // "platane"
    41, 37, 27, 45, 27, 39, 31,

    // "asperge"
    27, 44, 41, 31, 43, 33, 31,

    // "tulipe"
    45, 46, 37, 35, 41, 31,

    // "poule"
    41, 40, 46, 37, 31,

    // "bette"
    28, 31, 45, 45, 31,

    // "bouleau"
    28, 40, 46, 37, 31, 27, 46,

    // "jonquille"
    36, 40, 39, 42, 46, 35, 37, 37, 31,

    // "aulne"
    27, 46, 37, 39, 31,

    // "couvoir"
    29, 40, 46, 47, 40, 35, 43,

    // "perce-neige"
    41, 31, 43, 29, 31, 2, 39, 31, 35, 33, 31,

    // "crocus"
    29, 43, 40, 29, 46, 44,

    // "hêtre"
    34, 55, 45, 43, 31,

    // "laitue"
    37, 27, 35, 45, 46, 31,

    // "torillon"
    45, 40, 43, 35, 37, 37, 40, 39,

    // "lilas"
    37, 35, 37, 27, 44,

    // "anémone"
    27, 39, 54, 38, 40, 39, 31,

    // "pensée"
    41, 31, 39, 44, 54, 31,

    // "myrtille"
    38, 49, 43, 45, 35, 37, 37, 31,

    // "greffoir"
    33, 43, 31, 32, 32, 40, 35, 43,

    // "cerisier"
    29, 31, 43, 35, 44, 35, 31, 43,

    // "verveine"
    47, 31, 43, 47, 31, 35, 39, 31,

    // "grenadier"
    33, 43, 31, 39, 27, 30, 35, 31, 43,

    // "vernal"
    47, 31, 43, 39, 27, 37,

    // "cheval"
    29, 34, 31, 47, 27, 37,

    // "brenèche"
    28, 43, 31, 39, 53, 29, 34, 31,

    // "charme"
    29, 34, 27, 43, 38, 31,

    // "morille"
    38, 40, 43, 35, 37, 37, 31,

    // "hêtre enraciné"
    34, 55, 45, 43, 31, 0, 31, 39, 43, 27, 29, 35, 39, 54,

    // "ruche"
    43, 46, 29, 34, 31,

    // "rose"
    43, 40, 44, 31,

    // "chêne"
    29, 34, 55, 39, 31,

    // "fougère"
    32, 40, 46, 33, 53, 43, 31,

    // "aubépine"
    27, 46, 28, 54, 41, 35, 39, 31,

    // "rossignol"
    43, 40, 44, 44, 35, 33, 39, 40, 37,

    // "ancolie"
    27, 39, 29, 40, 37, 35, 31,

    // "muguet"
    38, 46, 33, 46, 31, 45,

    // "champignon"
    29, 34, 27, 38, 41, 35, 33, 39, 40, 39,

    // "hyacinthe"
    34, 49, 27, 29, 35, 39, 45, 34, 31,

    // "râteau"
    43, 52, 45, 31, 27, 46,

    // "rhubarbe"
    43, 34, 46, 28, 27, 43, 28, 31,

    // "sainfoin"
    44, 27, 35, 39, 32, 40, 35, 39,

    // "bâton-d'or"
    28, 52, 45, 40, 39, 2, 30, 1, 40, 43,

    // "chamerisier"
    29, 34, 27, 38, 31, 43, 35, 44, 35, 31, 43,

    // "ver à soie"
    47, 31, 43, 0, 51, 0, 44, 40, 35, 31,

    // "consoude"
    29, 40, 39, 44, 40, 46, 30, 31,

    // "pimprenelle"
    41, 35, 38, 41, 43, 31, 39, 31, 37, 37, 31,

    // "corbeille d'or"
    29, 40, 43, 28, 31, 35, 37, 37, 31, 0, 30, 1, 40, 43,

    // "arroche"
    27, 43, 43, 40, 29, 34, 31,

    // "sarcloir"
    44, 27, 43, 29, 37, 40, 35, 43,

    // "statice"
    44, 45, 27, 45, 35, 29, 31,

    // "fritillaire"
    32, 43, 35, 45, 35, 37, 37, 27, 35, 43, 31,

    // "bourache"
    28, 40, 46, 43, 27, 29, 34, 31,

    // "valériane"
    47, 27, 37, 54, 43, 35, 27, 39, 31,

    // "carpe"
    29, 27, 43, 41, 31,

    // "fusain"
    32, 46, 44, 27, 35, 39,

    // "civette"
    29, 35, 47, 31, 45, 45, 31,

    // "buglosse"
    28, 46, 33, 37, 40, 44, 44, 31,

    // "sénevé"
    44, 54, 39, 31, 47, 54,

    // "houlette"
    34, 40, 46, 37, 31, 45, 45, 31,

    // "luzerne"
    37, 46, 50, 31, 43, 39, 31,

    // "hémérocalle"
    34, 54, 38, 54, 43, 40, 29, 27, 37, 37, 31,

    // "trèfle"
    45, 43, 53, 32, 37, 31,

    // "angélique"
    27, 39, 33, 54, 37, 35, 42, 46, 31,

    // "canard"
    29, 27, 39, 27, 43, 30,

    // "mélisse"
    38, 54, 37, 35, 44, 44, 31,

    // "fromental"
    32, 43, 40, 38, 31, 39, 45, 27, 37,

    // "martagon"
    38, 27, 43, 45, 27, 33, 40, 39,

    // "serpolet"
    44, 31, 43, 41, 40, 37, 31, 45,

    // "faux"
    32, 27, 46, 48,

    // "fraise"
    32, 43, 27, 35, 44, 31,

    // "bétoine"
    28, 54, 45, 40, 35, 39, 31,

    // "pois"
    41, 40, 35, 44,

    // "acacia"
    27, 29, 27, 29, 35, 27,

    // "caille"
    29, 27, 35, 37, 37, 31,

    // "œillet"
    60, 35, 37, 37, 31, 45,

    // "sureau"
    44, 46, 43, 31, 27, 46,

    // "pavot"
    41, 27, 47, 40, 45,

    // "tilleul"
    45, 35, 37, 37, 31, 46, 37,

    // "fourche"
    32, 40, 46, 43, 29, 34, 31,

    // "barbeau"
    28, 27, 43, 28, 31, 27, 46,

    // "camomille"
    29, 27, 38, 40, 38, 35, 37, 37, 31,

    // "chévrefeuille"
    29, 34, 54, 47, 43, 31, 32, 31, 46, 35, 37, 37, 31,

    // "caille-lait"
    29, 27, 35, 37, 37, 31, 2, 37, 27, 35, 45,

    // "tanche"
    45, 27, 39, 29, 34, 31,

    // "jasmin"
    36, 27, 44, 38, 35, 39,

    // "verveine"
    47, 31, 43, 47, 31, 35, 39, 31,

    // "thym"
    45, 34, 49, 38,

    // "pivoine"
    41, 35, 47, 40, 35, 39, 31,

    // "chariot"
    29, 34, 27, 43, 35, 40, 45,

    // "seigle"
    44, 31, 35, 33, 37, 31,

    // "avoine"
    27, 47, 40, 35, 39, 31,

    // "oignon"
    40, 35, 33, 39, 40, 39,

    // "véronique"
    47, 54, 43, 40, 39, 35, 42, 46, 31,

    // "mulet"
    38, 46, 37, 31, 45,

    // "romaine"
    43, 40, 38, 27, 35, 39, 31,

    // "concombre"
    29, 40, 39, 29, 40, 38, 28, 43, 31,

    // "échalote"
    54, 29, 34, 27, 37, 40, 45, 31,

    // "absinthe"
    27, 28, 44, 35, 39, 45, 34, 31,

    // "faucille"
    32, 27, 46, 29, 35, 37, 37, 31,

    // "coriandre"
    29, 40, 43, 35, 27, 39, 30, 43, 31,

    // "artichaut"
    27, 43, 45, 35, 29, 34, 27, 46, 45,

    // "girofle"
    33, 35, 43, 40, 32, 37, 31,

    // "lavande"
    37, 27, 47, 27, 39, 30, 31,

    // "chamois"
    29, 34, 27, 38, 40, 35, 44,

    // "tabac"
    45, 27, 28, 27, 29,

    // "groseille"
    33, 43, 40, 44, 31, 35, 37, 37, 31,

    // "gesse"
    33, 31, 44, 44, 31,

    // "cerise"
    29, 31, 43, 35, 44, 31,

    // "parc"
    41, 27, 43, 29,

    // "menthe"
    38, 31, 39, 45, 34, 31,

    // "cumin"
    29, 46, 38, 35, 39,

    // "haricot"
    34, 27, 43, 35, 29, 40, 45,

    // "orcanète"
    40, 43, 29, 27, 39, 53, 45, 31,

    // "pintade"
    41, 35, 39, 45, 27, 30, 31,

    // "sauge"
    44, 27, 46, 33, 31,

    // "ail"
    27, 35, 37,

    // "vesce"
    47, 31, 44, 29, 31,

    // "blé"
    28, 37, 54,

    // "chalémie"
    29, 34, 27, 37, 54, 38, 35, 31,

    // "épeautre"
    54, 41, 31, 27, 46, 45, 43, 31,

    // "bouillon-blanc"
    28, 40, 46, 35, 37, 37, 40, 39, 2, 28, 37, 27, 39, 29,

    // "melon"
    38, 31, 37, 40, 39,

    // "ivraie"
    35, 47, 43, 27, 35, 31,

    // "bélier"
    28, 54, 37, 35, 31, 43,

    // "prêle"
    41, 43, 55, 37, 31,

    // "armoise"
    27, 43, 38, 40, 35, 44, 31,

    // "carthame"
    29, 27, 43, 45, 34, 27, 38, 31,

    // "mûre"
    38, 59, 43, 31,

    // "arrosoir"
    27, 43, 43, 40, 44, 40, 35, 43,

    // "panis"
    41, 27, 39, 35, 44,

    // "salicorne"
    44, 27, 37, 35, 29, 40, 43, 39, 31,

    // "abricot"
    27, 28, 43, 35, 29, 40, 45,

    // "basilic"
    28, 27, 44, 35, 37, 35, 29,

    // "brebis"
    28, 43, 31, 28, 35, 44,

    // "guimauve"
    33, 46, 35, 38, 27, 46, 47, 31,

    // "lin"
    37, 35, 39,

    // "amande"
    27, 38, 27, 39, 30, 31,

    // "gentiane"
    33, 31, 39, 45, 35, 27, 39, 31,

    // "écluse"
    54, 29, 37, 46, 44, 31,

    // "carline"
    29, 27, 43, 37, 35, 39, 31,

    // "câprier"
    29, 52, 41, 43, 35, 31, 43,

    // "lentille"
    37, 31, 39, 45, 35, 37, 37, 31,

    // "aunée"
    27, 46, 39, 54, 31,

    // "loutre"
    37, 40, 46, 45, 43, 31,

    // "myrte"
    38, 49, 43, 45, 31,

    // "colza"
    29, 40, 37, 50, 27,

    // "lupin"
    37, 46, 41, 35, 39,

    // "coton"
    29, 40, 45, 40, 39,

    // "moulin"
    38, 40, 46, 37, 35, 39,

    // "prune"
    41, 43, 46, 39, 31,

    // "millet"
    38, 35, 37, 37, 31, 45,

    // "lycoperdon"
    37, 49, 29, 40, 41, 31, 43, 30, 40, 39,

    // "escourgeon"
    31, 44, 29, 40, 46, 43, 33, 31, 40, 39,

    // "saumon"
    44, 27, 46, 38, 40, 39,

    // "tubéreuse"
    45, 46, 28, 54, 43, 31, 46, 44, 31,

    // "sucrion"
    44, 46, 29, 43, 35, 40, 39,

    // "apocyn"
    27, 41, 40, 29, 49, 39,

    // "réglisse"
    43, 54, 33, 37, 35, 44, 44, 31,

    // "échelle"
    54, 29, 34, 31, 37, 37, 31,

    // "pastèque"
    41, 27, 44, 45, 53, 42, 46, 31,

    // "fenouil"
    32, 31, 39, 40, 46, 35, 37,

    // "épine-vinette"
    54, 41, 35, 39, 31, 2, 47, 35, 39, 31, 45, 45, 31,

    // "noix"
    39, 40, 35, 48,

    // "truite"
    45, 43, 46, 35, 45, 31,

    // "citron"
    29, 35, 45, 43, 40, 39,

    // "cardère"
    29, 27, 43, 30, 53, 43, 31,

    // "nerprun"
    39, 31, 43, 41, 43, 46, 39,

    // "tagette"
    45, 27, 33, 31, 45, 45, 31,

    // "hotte"
    34, 40, 45, 45, 31,

    // "églantier"
    54, 33, 37, 27, 39, 45, 35, 31, 43,

    // "noisette"
    39, 40, 35, 44, 31, 45, 45, 31,

    // "houblon"
    34, 40, 46, 28, 37, 40, 39,

    // "sorgho"
    44, 40, 43, 33, 34, 40,

    // "écrevisse"
    54, 29, 43, 31, 47, 35, 44, 44, 31,

    // "bigarade"
    28, 35, 33, 27, 43, 27, 30, 31,

    // "verge d'or"
    47, 31, 43, 33, 31, 0, 30, 1, 40, 43,

    // "maïs"
    38, 27, 57, 44,

    // "marron"
    38, 27, 43, 43, 40, 39,

    // "panier"
    41, 27, 39, 35, 31, 43
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
    11, // bell: "🔔"
    12, // run: "run"
    15, // stop: "stop"
    19, // alarm: "alarm"
    24, // hour: "hour"
    28, // minute: "minute"
    34, // set: "set"
    37, // day: "day"
    40, // month: "month"
    45, // year: "year"
    49, // annee: "année"
    54, // on_off: "on"
    56, // "off"
    59, // months: "Vendémiaire"
    70, // "Brumaire"
    78, // "Frimaire"
    86, // "Nivôse"
    92, // "Pluviôse"
    100, // "Ventôse"
    107, // "Germinal"
    115, // "Floréal"
    122, // "Prairial"
    130, // "Messidor"
    138, // "Thermidor"
    147, // "Fructidor"
    156, // days: "Primidi"
    163, // "Duodi"
    168, // "Tridi"
    173, // "Quartidi"
    181, // "Quintidi"
    189, // "Sextidi"
    196, // "Septidi"
    203, // "Octidi"
    209, // "Nonidi"
    215, // "Décadi"
    221, // sansculottides: "Fête de la Vertu"
    237, // "Fête du Génie"
    250, // "Fête du Travail"
    265, // "Fête de l'Opinion"
    282, // "Fête des Récompenses"
    302, // "Fête de la Révolution"
    323, // day_of_year: "raisin"
    329, // "safran"
    335, // "châtaigne"
    344, // "colchique"
    353, // "cheval"
    359, // "balsamine"
    368, // "carotte"
    375, // "amarante"
    383, // "panais"
    389, // "cuve"
    393, // "pomme de terre"
    407, // "immortelle"
    417, // "potiron"
    424, // "réséda"
    430, // "âne"
    433, // "belle de nuit"
    446, // "citrouille"
    456, // "sarrasin"
    464, // "tournesol"
    473, // "pressoir"
    481, // "chanvre"
    488, // "pêche"
    493, // "navet"
    498, // "amaryllis"
    507, // "bœuf"
    511, // "aubergine"
    520, // "piment"
    526, // "tomate"
    532, // "orge"
    536, // "tonneau"
    543, // "pomme"
    548, // "céleri"
    554, // "poire"
    559, // "betterave"
    568, // "oie"
    571, // "héliotrope"
    581, // "figue"
    586, // "scorsonère"
    596, // "alisier"
    603, // "charrue"
    610, // "salsifis"
    618, // "macre"
    623, // "topinambour"
    634, // "endive"
    640, // "dindon"
    646, // "chervis"
    653, // "cresson"
    660, // "dentelaire"
    670, // "grenade"
    677, // "herse"
    682, // "bacchante"
    691, // "azerole"
    698, // "garance"
    705, // "orange"
    711, // "faisan"
    717, // "pistache"
    725, // "macjonc"
    732, // "coing"
    737, // "cormier"
    744, // "rouleau"
    751, // "raiponce"
    759, // "turneps"
    766, // "chicorée"
    774, // "nèfle"
    779, // "cochon"
    785, // "mâche"
    790, // "chou-fleur"
    800, // "miel"
    804, // "génépi"
    810, // "pioche"
    816, // "cire"
    820, // "raifort"
    827, // "cèdre"
    832, // "sapin"
    837, // "chevreuil"
    846, // "ajonc"
    851, // "cyprès"
    857, // "lierre"
    863, // "sabine"
    869, // "hoye"
    873, // "érable sucré"
    885, // "bruyère"
    892, // "roseau"
    898, // "oseille"
    905, // "grillon"
    912, // "pignon"
    918, // "liège"
    923, // "truffe"
    929, // "olive"
    934, // "pelle"
    939, // "tourbe"
    945, // "houille"
    952, // "bitume"
    958, // "soufre"
    964, // "chien"
    969, // "lave"
    973, // "terre végétale"
    987, // "fumier"
    993, // "salpêtre"
    1001, // "fléau"
    1006, // "granite"
    1013, // "argile"
    1019, // "ardoise"
    1026, // "grès"
    1030, // "lapin"
    1035, // "silex"
    1040, // "marne"
    1045, // "pierre à chaux"
    1059, // "marbre"
    1065, // "van"
    1068, // "pierre à plâtre"
    1083, // "sel"
    1086, // "fer"
    1089, // "cuivre"
    1095, // "chat"
    1099, // "étain"
    1104, // "plomb"
    1109, // "zinc"
    1113, // "mercure"
    1120, // "crible"
    1126, // "lauréole"
    1134, // "mousse"
    1140, // "fragon"
    1146, // "pervenche"
    1155, // "taureau"
    1162, // "laurier-tin"
    1173, // "amatyste"
    1181, // "mézéréon"
    1189, // "peuplier"
    1197, // "coignée"
    1204, // "ellébore"
    1212, // "brocoli"
    1219, // "laurier"
    1226, // "avelinier"
    1235, // "vache"
    1240, // "buis"
    1244, // "lichén"
    1250, // "if"
    1252, // "pulmonaire"
    1262, // "serpette"
    1270, // "thlaspi"
    1277, // "thimelé"
    1284, // "chiendent"
    1293, // "traînasse"
    1302, // "lièvre"
    1308, // "guède"
    1313, // "noisetier"
    1322, // "cyclamen"
    1330, // "chélidoine"
    1340, // "traîneau"
    1348, // "tussilage"
    1357, // "cornouiller"
    1368, // "violier"
    1375, // "troène"
    1381, // "bouc"
    1385, // "asaret"
    1391, // "alaterne"
    1399, // "violette"
    1407, // "marceau"
    1414, // "bêche"
    1419, // "narcisse"
    1427, // "orme"
    1431, // "fumeterre"
    1440, // "vélar"
    1445, // "chèvre"
    1451, // "épinard"
    1458, // "doronic"
    1465, // "mouron"
    1471, // "cerfeuil"
    1479, // "cordeau"
    1486, // "mandragore"
    1496, // "persil"
    1502, // "cochléaria"
    1512, // "pâquerette"
    1522, // "thon"
    1526, // "pissenlit"
    1535, // "sylvie"
    1541, // "capillaire"
    1551, // "frêne"
    1556, // "plantoir"
    1564, // "primevère"
    1573, // "platane"
    1580, // "asperge"
    1587, // "tulipe"
    1593, // "poule"
    1598, // "bette"
    1603, // "bouleau"
    1610, // "jonquille"
    1619, // "aulne"
    1624, // "couvoir"
    1631, // "perce-neige"
    1642, // "crocus"
    1648, // "hêtre"
    1653, // "laitue"
    1659, // "torillon"
    1667, // "lilas"
    1672, // "anémone"
    1679, // "pensée"
    1685, // "myrtille"
    1693, // "greffoir"
    1701, // "cerisier"
    1709, // "verveine"
    1717, // "grenadier"
    1726, // "vernal"
    1732, // "cheval"
    1738, // "brenèche"
    1746, // "charme"
    1752, // "morille"
    1759, // "hêtre enraciné"
    1773, // "ruche"
    1778, // "rose"
    1782, // "chêne"
    1787, // "fougère"
    1794, // "aubépine"
    1802, // "rossignol"
    1811, // "ancolie"
    1818, // "muguet"
    1824, // "champignon"
    1834, // "hyacinthe"
    1843, // "râteau"
    1849, // "rhubarbe"
    1857, // "sainfoin"
    1865, // "bâton-d'or"
    1875, // "chamerisier"
    1886, // "ver à soie"
    1896, // "consoude"
    1904, // "pimprenelle"
    1915, // "corbeille d'or"
    1929, // "arroche"
    1936, // "sarcloir"
    1944, // "statice"
    1951, // "fritillaire"
    1962, // "bourache"
    1970, // "valériane"
    1979, // "carpe"
    1984, // "fusain"
    1990, // "civette"
    1997, // "buglosse"
    2005, // "sénevé"
    2011, // "houlette"
    2019, // "luzerne"
    2026, // "hémérocalle"
    2037, // "trèfle"
    2043, // "angélique"
    2052, // "canard"
    2058, // "mélisse"
    2065, // "fromental"
    2074, // "martagon"
    2082, // "serpolet"
    2090, // "faux"
    2094, // "fraise"
    2100, // "bétoine"
    2107, // "pois"
    2111, // "acacia"
    2117, // "caille"
    2123, // "œillet"
    2129, // "sureau"
    2135, // "pavot"
    2140, // "tilleul"
    2147, // "fourche"
    2154, // "barbeau"
    2161, // "camomille"
    2170, // "chévrefeuille"
    2183, // "caille-lait"
    2194, // "tanche"
    2200, // "jasmin"
    2206, // "verveine"
    2214, // "thym"
    2218, // "pivoine"
    2225, // "chariot"
    2232, // "seigle"
    2238, // "avoine"
    2244, // "oignon"
    2250, // "véronique"
    2259, // "mulet"
    2264, // "romaine"
    2271, // "concombre"
    2280, // "échalote"
    2288, // "absinthe"
    2296, // "faucille"
    2304, // "coriandre"
    2313, // "artichaut"
    2322, // "girofle"
    2329, // "lavande"
    2336, // "chamois"
    2343, // "tabac"
    2348, // "groseille"
    2357, // "gesse"
    2362, // "cerise"
    2368, // "parc"
    2372, // "menthe"
    2378, // "cumin"
    2383, // "haricot"
    2390, // "orcanète"
    2398, // "pintade"
    2405, // "sauge"
    2410, // "ail"
    2413, // "vesce"
    2418, // "blé"
    2421, // "chalémie"
    2429, // "épeautre"
    2437, // "bouillon-blanc"
    2451, // "melon"
    2456, // "ivraie"
    2462, // "bélier"
    2468, // "prêle"
    2473, // "armoise"
    2480, // "carthame"
    2488, // "mûre"
    2492, // "arrosoir"
    2500, // "panis"
    2505, // "salicorne"
    2514, // "abricot"
    2521, // "basilic"
    2528, // "brebis"
    2534, // "guimauve"
    2542, // "lin"
    2545, // "amande"
    2551, // "gentiane"
    2559, // "écluse"
    2565, // "carline"
    2572, // "câprier"
    2579, // "lentille"
    2587, // "aunée"
    2592, // "loutre"
    2598, // "myrte"
    2603, // "colza"
    2608, // "lupin"
    2613, // "coton"
    2618, // "moulin"
    2624, // "prune"
    2629, // "millet"
    2635, // "lycoperdon"
    2645, // "escourgeon"
    2655, // "saumon"
    2661, // "tubéreuse"
    2670, // "sucrion"
    2677, // "apocyn"
    2683, // "réglisse"
    2691, // "échelle"
    2698, // "pastèque"
    2706, // "fenouil"
    2713, // "épine-vinette"
    2726, // "noix"
    2730, // "truite"
    2736, // "citron"
    2742, // "cardère"
    2749, // "nerprun"
    2756, // "tagette"
    2763, // "hotte"
    2768, // "églantier"
    2777, // "noisette"
    2785, // "houblon"
    2792, // "sorgho"
    2798, // "écrevisse"
    2807, // "bigarade"
    2815, // "verge d'or"
    2825, // "maïs"
    2829, // "marron"
    2835, // "panier"
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
    5, // annee: "année"
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
    15, // '0'
    11, // '1'
    15, // '2'
    15, // '3'
    16, // '4'
    14, // '5'
    15, // '6'
    15, // '7'
    15, // '8'
    15, // '9'
    6, // ':'
};

// big font character begin positions
const std::array<uint16_t, big_font_len> big_font_char_begin = {
    0, // '0'
    74, // '1'
    128, // '2'
    202, // '3'
    276, // '4'
    354, // '5'
    423, // '6'
    497, // '7'
    571, // '8'
    645, // '9'
    719, // ':'
};

// big font content (bitmap data, packed)
const std::array<uint8_t, 749> big_font_content = {
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
    //               
    //               
    //               
    //               
    //      #####    
    //    ########   
    //    #########  
    //   ####   #### 
    //   ###    #### 
    //  ####     ### 
    //  ####     ####
    //  ###      ####
    //  ###      ####
    //  ###      ####
    // ####       ###
    // ####       ###
    // ####       ###
    // ####       ###
    // ####       ###
    // ####      ####
    //  ###      ####
    //  ###      ####
    //  ###      ####
    //  ####     ####
    //  ####     ### 
    //  ####    #### 
    //   ####   #### 
    //   ##########  
    //    ########   
    //      #####    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x80,
    0x7F,
    0xE0,
    0x3F,
    0x3C,
    0x1E,
    0x87,
    0xE7,
    0xC1,
    0x79,
    0xF0,
    0x0E,
    0xBC,
    0x03,
    0xEF,
    0xC0,
    0x3F,
    0xE0,
    0x0F,
    0xF8,
    0x03,
    0xFE,
    0x80,
    0x3F,
    0xE0,
    0x0F,
    0xBC,
    0x03,
    0xEF,
    0xC0,
    0x3B,
    0xF0,
    0x1E,
    0xBC,
    0x07,
    0xE7,
    0xE1,
    0xF1,
    0x78,
    0xFC,
    0x0F,
    0xFE,
    0x01,
    0x3E,
    0x00,
    0x00,
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
    //           
    //           
    //           
    //           
    //       ####
    //      #####
    //     ######
    //    #######
    //   ########
    //  #### ####
    // ####  ####
    //  ##   ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    //       ####
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x0F,
    0x3E,
    0xFC,
    0xF8,
    0xF3,
    0xEF,
    0xFD,
    0xF3,
    0xC6,
    0x03,
    0x0F,
    0x3C,
    0xF0,
    0xC0,
    0x03,
    0x0F,
    0x3C,
    0xF0,
    0xC0,
    0x03,
    0x0F,
    0x3C,
    0xF0,
    0xC0,
    0x03,
    0x0F,
    0x3C,
    0xF0,
    0xC0,
    0x03,
    0x0F,
    0x3C,
    0x00,
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
    //               
    //               
    //               
    //               
    //               
    //               
    //     ######    
    //   #########   
    // ############  
    //  ####   ##### 
    //   #      #### 
    //           ### 
    //           ### 
    //           ### 
    //           ### 
    //          #### 
    //          #### 
    //          #### 
    //         ####  
    //        ####   
    //        ####   
    //       ####    
    //      ####     
    //      ####     
    //     ####      
    //    ####       
    //   #####       
    //   ####        
    //  ####         
    // ##############
    // ##############
    // ##############
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0xC0,
    0x7F,
    0xFC,
    0x3F,
    0x1E,
    0x1F,
    0x81,
    0x07,
    0xC0,
    0x01,
    0x70,
    0x00,
    0x1C,
    0x00,
    0x07,
    0xE0,
    0x01,
    0x78,
    0x00,
    0x1E,
    0xC0,
    0x03,
    0x78,
    0x00,
    0x1E,
    0xC0,
    0x03,
    0x78,
    0x00,
    0x1E,
    0xC0,
    0x03,
    0x78,
    0x00,
    0x1F,
    0xC0,
    0x03,
    0x78,
    0x00,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x03,
    0x00,
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
    //               
    //               
    //               
    //               
    //               
    //               
    //     ######    
    //   ##########  
    // ############  
    //  ###    ##### 
    //   #      #### 
    //           ### 
    //           ####
    //           ### 
    //          #### 
    //          #### 
    //        #####  
    //    ########   
    //    #######    
    //    #########  
    //         ##### 
    //          #### 
    //           ####
    //           ####
    //           ####
    //           ####
    //           ####
    // #        #####
    // ###     ##### 
    // ############  
    // ###########   
    //   #######     
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0xC0,
    0xFF,
    0xFC,
    0x3F,
    0x0E,
    0x1F,
    0x81,
    0x07,
    0xC0,
    0x01,
    0xF0,
    0x00,
    0x1C,
    0x80,
    0x07,
    0xE0,
    0x01,
    0x3E,
    0xF8,
    0x07,
    0xFE,
    0x80,
    0xFF,
    0x00,
    0x7C,
    0x00,
    0x1E,
    0x00,
    0x0F,
    0xC0,
    0x03,
    0xF0,
    0x00,
    0x3C,
    0x00,
    0x1F,
    0xE0,
    0x1F,
    0x7C,
    0xFF,
    0xCF,
    0xFF,
    0xC1,
    0x1F,
    0x00,
    0x00,
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
    //                
    //                
    //                
    //                
    //         ####   
    //         ####   
    //        #####   
    //        #####   
    //       ######   
    //       ## ###   
    //      ### ###   
    //      ### ###   
    //     ###  ###   
    //     ###  ###   
    //    ###   ###   
    //    ###   ###   
    //   ###    ###   
    //   ###    ###   
    //  ###     ###   
    // ####     ###   
    // ###      ###   
    // ###############
    // ###############
    // ###############
    //          ###   
    //          ###   
    //          ###   
    //          ###   
    //          ###   
    //          ###   
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x00,
    0x3C,
    0x00,
    0x1F,
    0x80,
    0x0F,
    0xE0,
    0x07,
    0xB0,
    0x03,
    0xDC,
    0x01,
    0xEE,
    0x80,
    0x73,
    0xC0,
    0x39,
    0x70,
    0x1C,
    0x38,
    0x0E,
    0x0E,
    0x07,
    0x87,
    0xC3,
    0xC1,
    0xF1,
    0xE0,
    0x38,
    0x70,
    0xFC,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x7F,
    0x00,
    0x07,
    0x80,
    0x03,
    0xC0,
    0x01,
    0xE0,
    0x00,
    0x70,
    0x00,
    0x38,
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
    //              
    //              
    //              
    //              
    //              
    //              
    //  ########### 
    //  ########### 
    //  ########### 
    //  ###         
    //  ###         
    //  ###         
    // ####         
    // ####         
    // ####         
    // ####         
    // #########    
    // ###########  
    // ############ 
    //  #     ##### 
    //         #####
    //          ####
    //          ####
    //          ####
    //          ####
    //          ####
    //          ####
    // #       #### 
    // ##     ##### 
    // ###########  
    // ##########   
    //  #######     
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x9F,
    0xFF,
    0xF3,
    0x7F,
    0x0E,
    0xC0,
    0x01,
    0x38,
    0x80,
    0x07,
    0xF0,
    0x00,
    0x1E,
    0xC0,
    0x03,
    0xF8,
    0x0F,
    0xFF,
    0xE7,
    0xFF,
    0x09,
    0x3E,
    0x80,
    0x0F,
    0xE0,
    0x01,
    0x3C,
    0x80,
    0x07,
    0xF0,
    0x00,
    0x1E,
    0xC0,
    0x07,
    0xBC,
    0xC1,
    0xF7,
    0x7F,
    0xFE,
    0x87,
    0x3F,
    0x00,
    0x00,
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
    //               
    //               
    //               
    //               
    //        ###### 
    //      ######## 
    //     ######### 
    //    #####      
    //   ####        
    //   ###         
    //   ###         
    //  ####         
    //  ###          
    //  ###  #####   
    //  ### #######  
    //  ############ 
    //  #####   #### 
    // #####     ####
    // #####     ####
    // ####       ###
    // ####       ###
    //  ###       ###
    //  ###       ###
    //  ####     ####
    //  ####     ####
    //   ###     ####
    //   ####   #### 
    //    ########## 
    //     ########  
    //      #####    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x07,
    0xFE,
    0xC1,
    0x7F,
    0xF8,
    0x00,
    0x0F,
    0xC0,
    0x01,
    0x70,
    0x00,
    0x1E,
    0x80,
    0x03,
    0xE0,
    0x7C,
    0xB8,
    0x3F,
    0xFE,
    0x9F,
    0x8F,
    0xF7,
    0xC1,
    0x7F,
    0xF0,
    0x0F,
    0xF8,
    0x03,
    0xEE,
    0x80,
    0x3B,
    0xE0,
    0x1E,
    0xBC,
    0x07,
    0xCF,
    0xC1,
    0xF3,
    0x78,
    0xF8,
    0x1F,
    0xFC,
    0x03,
    0x3E,
    0x00,
    0x00,
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
    //               
    //               
    //               
    //               
    // ##############
    // ##############
    // ##############
    //           ####
    //           ####
    //           ### 
    //          #### 
    //          #### 
    //          ###  
    //         ####  
    //         ####  
    //         ###   
    //        ####   
    //        ####   
    //        ###    
    //       ####    
    //       ####    
    //      ####     
    //      ####     
    //      ####     
    //     ####      
    //     ####      
    //     ####      
    //    ####       
    //    ####       
    //   #####       
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x00,
    0x3C,
    0x00,
    0x0F,
    0xC0,
    0x01,
    0x78,
    0x00,
    0x1E,
    0x80,
    0x03,
    0xF0,
    0x00,
    0x3C,
    0x00,
    0x07,
    0xE0,
    0x01,
    0x78,
    0x00,
    0x0E,
    0xC0,
    0x03,
    0xF0,
    0x00,
    0x1E,
    0x80,
    0x07,
    0xE0,
    0x01,
    0x3C,
    0x00,
    0x0F,
    0xC0,
    0x03,
    0x78,
    0x00,
    0x1E,
    0xC0,
    0x07,
    0x00,
    0x00,
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
    //               
    //               
    //               
    //               
    //     ######    
    //    #########  
    //   ########### 
    //  #####   #### 
    //  ####     ####
    //  ####     ####
    //  ###      ####
    //  ####     ####
    //  ####     ### 
    //   ####   #### 
    //   ##### ####  
    //    ########   
    //     ######    
    //    ########   
    //   ####  ####  
    //  ####    #### 
    //  ###      ####
    // ####       ###
    // ####       ###
    // ####       ###
    // ####       ###
    //  ###      ####
    //  ####    #####
    //  ############ 
    //   ##########  
    //     ######    
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x80,
    0xFF,
    0xF0,
    0x7F,
    0x3E,
    0x9E,
    0x07,
    0xEF,
    0xC1,
    0x3B,
    0xF0,
    0x1E,
    0xBC,
    0x07,
    0xC7,
    0xE3,
    0xF1,
    0x3D,
    0xF8,
    0x07,
    0xFC,
    0x80,
    0x7F,
    0xF0,
    0x3C,
    0x1E,
    0x9E,
    0x03,
    0xFF,
    0x80,
    0x3F,
    0xE0,
    0x0F,
    0xF8,
    0x03,
    0xEE,
    0xC0,
    0x7B,
    0xF8,
    0xFE,
    0x1F,
    0xFF,
    0x03,
    0x3F,
    0x00,
    0x00,
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
    //               
    //               
    //               
    //               
    //     ######    
    //    ########   
    //   ##########  
    //  #####   #### 
    //  ####    #### 
    //  ###      ### 
    // ####      ####
    // ####      ####
    // ####      ####
    // ####      ####
    // ####      ####
    //  ####     ####
    //  ####    #####
    //   ######## ###
    //   ######## ###
    //     ####  ####
    //           ####
    //           ####
    //           ### 
    //          #### 
    //          #### 
    //         ####  
    //  #     #####  
    //   #########   
    //   ########    
    //   ######      
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0x80,
    0x7F,
    0xF0,
    0x3F,
    0x3E,
    0x9E,
    0x87,
    0xE7,
    0xC0,
    0x3D,
    0xF0,
    0x0F,
    0xFC,
    0x03,
    0xFF,
    0xC0,
    0x3F,
    0xF0,
    0x1E,
    0xBC,
    0x87,
    0xCF,
    0xBF,
    0xF3,
    0xEF,
    0xF0,
    0x3C,
    0x00,
    0x0F,
    0xC0,
    0x03,
    0x70,
    0x00,
    0x1E,
    0x80,
    0x07,
    0xF0,
    0x08,
    0x3E,
    0xFC,
    0x07,
    0xFF,
    0xC0,
    0x0F,
    0x00,
    0x00,
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
    //      
    //      
    //      
    //  ### 
    // #### 
    // #####
    // #### 
    //  ### 
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
    //  ### 
    // #### 
    // #####
    // #### 
    //  ### 
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xF7,
    0xFE,
    0x73,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xB8,
    0xF7,
    0x9F,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};

// normal font character widths
const std::array<uint8_t, normal_font_len> normal_font_char_widths = {
    5, // ' '
    3, // '''
    6, // '-'
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
    9, // 'B'
    9, // 'D'
    7, // 'F'
    9, // 'G'
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
    0, // ' '
    15, // '''
    24, // '-'
    42, // '0'
    66, // '1'
    84, // '2'
    108, // '3'
    132, // '4'
    159, // '5'
    183, // '6'
    207, // '7'
    231, // '8'
    255, // '9'
    279, // ':'
    288, // 'B'
    315, // 'D'
    342, // 'F'
    363, // 'G'
    390, // 'M'
    426, // 'N'
    456, // 'O'
    486, // 'P'
    510, // 'Q'
    540, // 'R'
    567, // 'S'
    588, // 'T'
    615, // 'V'
    645, // 'a'
    666, // 'b'
    690, // 'c'
    711, // 'd'
    735, // 'e'
    759, // 'f'
    780, // 'g'
    804, // 'h'
    828, // 'i'
    837, // 'j'
    849, // 'l'
    858, // 'm'
    894, // 'n'
    918, // 'o'
    942, // 'p'
    966, // 'q'
    990, // 'r'
    1008, // 's'
    1026, // 't'
    1044, // 'u'
    1068, // 'v'
    1095, // 'x'
    1119, // 'y'
    1146, // 'z'
    1167, // 'à'
    1188, // 'â'
    1209, // 'è'
    1233, // 'é'
    1257, // 'ê'
    1281, // 'î'
    1299, // 'ï'
    1311, // 'ô'
    1335, // 'û'
    1359, // 'œ'
    1398, // '🔔' (custom bell bitmap)
};

// normal font content (bitmap data, packed)
const std::array<uint8_t, 1428> normal_font_content = {
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
    0xC0,
    0xFF,
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
    0xC0,
    0xFF,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

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
    0x3C,
    0xBE,
    0xD9,
    0x68,
    0x3C,
    0x1E,
    0x8F,
    0xC7,
    0xA3,
    0x99,
    0xCF,
    0x03,
    0x00,
    0x00,
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
    0xC0,
    0xDC,
    0x6F,
    0x8C,
    0x31,
    0xC6,
    0x18,
    0x63,
    0x0C,
    0x00,
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
    0x3C,
    0xBF,
    0x18,
    0x0C,
    0x06,
    0xC3,
    0x60,
    0x18,
    0x06,
    0xC3,
    0xFF,
    0x0F,
    0x00,
    0x00,
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
    0x3C,
    0xBF,
    0x18,
    0x0C,
    0xE6,
    0xF1,
    0xC0,
    0x40,
    0x60,
    0xD8,
    0xEF,
    0x03,
    0x00,
    0x00,
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
    0x60,
    0x70,
    0x70,
    0x68,
    0x6C,
    0x64,
    0x66,
    0x62,
    0xFF,
    0xFF,
    0x60,
    0x60,
    0x60,
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
    0x7E,
    0xBF,
    0xC1,
    0x60,
    0xF0,
    0xF9,
    0xC1,
    0xC0,
    0x60,
    0xD8,
    0xEF,
    0x03,
    0x00,
    0x00,
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
    0x78,
    0x3E,
    0xC1,
    0x60,
    0xF1,
    0x9B,
    0x8D,
    0xC7,
    0xE3,
    0x91,
    0x8F,
    0x03,
    0x00,
    0x00,
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
    0xFE,
    0x7F,
    0x18,
    0x0C,
    0x86,
    0xC1,
    0x60,
    0x18,
    0x0C,
    0x86,
    0xC1,
    0x00,
    0x00,
    0x00,
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
    0x3C,
    0xBF,
    0xD1,
    0x68,
    0xE6,
    0xF1,
    0xCC,
    0xC6,
    0xE1,
    0xF1,
    0xCF,
    0x03,
    0x00,
    0x00,
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
    0x3C,
    0xBF,
    0xD9,
    0x28,
    0x3C,
    0xFF,
    0xBB,
    0x40,
    0x30,
    0xD8,
    0xE7,
    0x01,
    0x00,
    0x00,
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
    0xF0,
    0x03,
    0xFC,
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
    0x3F,
    0x7F,
    0x63,
    0x63,
    0x63,
    0x7F,
    0x3F,
    0x63,
    0xC3,
    0xC3,
    0x63,
    0x7F,
    0x3F,
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
    0x3F,
    0x7F,
    0xE3,
    0xC3,
    0xC3,
    0xC3,
    0xC3,
    0xC3,
    0xC3,
    0xC3,
    0xE3,
    0x7F,
    0x3F,
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
    0xFC,
    0xFF,
    0x30,
    0x0C,
    0xC3,
    0xFF,
    0x0F,
    0xC3,
    0x30,
    0x0C,
    0x00,
    0x00,
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
    0xF8,
    0xFE,
    0x06,
    0x03,
    0x03,
    0x03,
    0xE3,
    0xE3,
    0x83,
    0x83,
    0x86,
    0xFE,
    0xF8,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
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
    0xE0,
    0xC0,
    0x07,
    0x7F,
    0xF8,
    0x43,
    0x17,
    0xBA,
    0xD8,
    0x4D,
    0x6E,
    0x72,
    0x9A,
    0xF3,
    0x9C,
    0xE3,
    0x18,
    0xC7,
    0x08,
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
    0x80,
    0xC3,
    0x87,
    0x1F,
    0x3F,
    0xDE,
    0xBC,
    0x79,
    0xF6,
    0xEC,
    0xD1,
    0xE3,
    0xC7,
    0x0F,
    0x1F,
    0x0E,
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
    0x3E,
    0xFE,
    0x8C,
    0x0D,
    0x1E,
    0x3C,
    0x78,
    0xF0,
    0xE0,
    0xC1,
    0x83,
    0x8D,
    0xF9,
    0xE3,
    0x03,
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
    0x7E,
    0xFF,
    0xF1,
    0x78,
    0x3C,
    0xFE,
    0x7D,
    0x06,
    0x83,
    0xC1,
    0x60,
    0x00,
    0x00,
    0x00,
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
    0x3E,
    0xFE,
    0x8C,
    0x0D,
    0x1E,
    0x3C,
    0x78,
    0xF0,
    0xE0,
    0xC1,
    0x83,
    0x8D,
    0xF9,
    0xE3,
    0x03,
    0x06,
    0x18,
    0x70,
    0x00,
    0x00,
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
    0x3F,
    0x7F,
    0x63,
    0x63,
    0x63,
    0x63,
    0x3F,
    0x1F,
    0x33,
    0x33,
    0x63,
    0x63,
    0xC3,
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
    0xF8,
    0xFF,
    0x30,
    0x0C,
    0x87,
    0x87,
    0xC3,
    0x30,
    0xFC,
    0x7F,
    0x00,
    0x00,
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
    0xFF,
    0xFF,
    0x18,
    0x18,
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
    0x80,
    0xC1,
    0x83,
    0x8C,
    0x19,
    0x33,
    0x66,
    0x84,
    0x0C,
    0x1B,
    0x36,
    0x2C,
    0x70,
    0xE0,
    0xC0,
    0x01,
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
    0xF0,
    0xF9,
    0x30,
    0xEC,
    0xFF,
    0x73,
    0xFC,
    0xBA,
    0x00,
    0x00,
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
    0x0C,
    0x06,
    0x83,
    0xC1,
    0xEE,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0x7F,
    0x07,
    0x00,
    0x00,
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
    0xC0,
    0x7B,
    0xC3,
    0x30,
    0x0C,
    0xC3,
    0xF0,
    0x79,
    0x00,
    0x00,
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
    0x80,
    0xC1,
    0x60,
    0xB0,
    0xFB,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0xDF,
    0x0D,
    0x00,
    0x00,
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
    0x80,
    0xC7,
    0x37,
    0x1A,
    0xFD,
    0xFF,
    0x83,
    0x81,
    0x8F,
    0x07,
    0x00,
    0x00,
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
    0xC0,
    0x73,
    0x86,
    0xF1,
    0x7D,
    0x86,
    0x61,
    0x18,
    0x86,
    0x61,
    0x18,
    0x00,
    0x00,
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
    0x80,
    0xFB,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0xDF,
    0x0D,
    0x06,
    0xFF,
    0x3E,
    0x00,
    0x00,
    0x00,

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
    0x0C,
    0x06,
    0x83,
    0xC1,
    0xEE,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0x78,
    0x0C,
    0x00,
    0x00,
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
    0xF0,
    0xF0,
    0xFF,
    0xFF,
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
    0xD8,
    0x80,
    0x6D,
    0xDB,
    0xB6,
    0x6D,
    0x7F,
    0x00,
    0x00,
    0x00,

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
    0xF0,
    0xFF,
    0xFF,
    0xFF,
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
    0xC0,
    0xEE,
    0xFE,
    0x3F,
    0xE6,
    0x31,
    0x8E,
    0x71,
    0x8C,
    0x63,
    0x1C,
    0xE3,
    0x18,
    0xC7,
    0x08,
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
    0xC0,
    0xEE,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0x78,
    0x0C,
    0x00,
    0x00,
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
    0x80,
    0xC7,
    0x37,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xB1,
    0x8F,
    0x03,
    0x00,
    0x00,
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
    0xC0,
    0xEE,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0x7F,
    0x37,
    0x18,
    0x0C,
    0x06,
    0x00,
    0x00,
    0x00,

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
    0x80,
    0xFB,
    0x3F,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0xDF,
    0x0D,
    0x06,
    0x83,
    0xC1,
    0x00,
    0x00,
    0x00,

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
    0xEC,
    0x3F,
    0xC6,
    0x18,
    0x63,
    0x8C,
    0x01,
    0x00,
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
    0xF8,
    0x1F,
    0xC6,
    0xE1,
    0x18,
    0xFF,
    0x07,
    0x00,
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
    0x84,
    0xFC,
    0x6F,
    0x8C,
    0x31,
    0xC6,
    0x78,
    0x0E,
    0x00,
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
    0xC0,
    0x78,
    0x3C,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0xDD,
    0x0D,
    0x00,
    0x00,
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
    0xC3,
    0x63,
    0x66,
    0x66,
    0x26,
    0x34,
    0x34,
    0x1C,
    0x1C,
    0x18,
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
    0xC0,
    0xD9,
    0x4C,
    0xE3,
    0x61,
    0x38,
    0x3C,
    0x9B,
    0x79,
    0x0C,
    0x00,
    0x00,
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
    0xC3,
    0x63,
    0x66,
    0x66,
    0x26,
    0x34,
    0x3C,
    0x1C,
    0x18,
    0x18,
    0x18,
    0x0C,
    0x0F,
    0x07,
    0x00,
    0x00,
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
    0xE0,
    0xFB,
    0x18,
    0xC6,
    0x30,
    0x84,
    0xE1,
    0xFF,
    0x00,
    0x00,
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
    0x60,
    0x30,
    0x08,
    0xF0,
    0xF9,
    0x30,
    0xEC,
    0xFF,
    0x73,
    0xFC,
    0xBA,
    0x00,
    0x00,
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
    0xC0,
    0x78,
    0x32,
    0xF0,
    0xF9,
    0x30,
    0xEC,
    0xFF,
    0x73,
    0xFC,
    0xBA,
    0x00,
    0x00,
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
    0x18,
    0x18,
    0x08,
    0x80,
    0xC7,
    0x37,
    0x1A,
    0xFD,
    0xFF,
    0x83,
    0x81,
    0x8F,
    0x07,
    0x00,
    0x00,
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
    0xC0,
    0x30,
    0x0C,
    0x80,
    0xC7,
    0x37,
    0x1A,
    0xFD,
    0xFF,
    0x83,
    0x81,
    0x8F,
    0x07,
    0x00,
    0x00,
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
    0x30,
    0x3C,
    0x32,
    0x80,
    0xC7,
    0x37,
    0x1A,
    0xFD,
    0xFF,
    0x83,
    0x81,
    0x8F,
    0x07,
    0x00,
    0x00,
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
    0x80,
    0x79,
    0x19,
    0x18,
    0x63,
    0x8C,
    0x31,
    0xC6,
    0x18,
    0x03,
    0x00,
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
    0x80,
    0xC4,
    0xB6,
    0x6D,
    0xDB,
    0x06,
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
    0x30,
    0x28,
    0x32,
    0x80,
    0xC7,
    0x37,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xB1,
    0x8F,
    0x03,
    0x00,
    0x00,
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
    0x70,
    0x28,
    0x22,
    0xC0,
    0x78,
    0x3C,
    0x1E,
    0x8F,
    0xC7,
    0xE3,
    0xF1,
    0xDD,
    0x0D,
    0x00,
    0x00,
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
    0x9E,
    0xE3,
    0x7F,
    0x63,
    0x3C,
    0xC6,
    0xE3,
    0x3F,
    0xFE,
    0x63,
    0x30,
    0x06,
    0xFE,
    0xC7,
    0x79,
    0x00,
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
    0x38,
    0xF8,
    0xF8,
    0xF3,
    0xF7,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xBF,
    0x3F,
    0x00,
    0x38,
    0x70,
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
