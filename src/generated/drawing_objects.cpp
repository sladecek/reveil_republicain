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

    // annee: "année "
    27, 39, 39, 54, 31, 11,

    // decade: " Décade "
    11, 15, 54, 29, 27, 30, 31, 11,

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
    16, 55, 45, 31, 11, 30, 31, 11, 37, 27, 11, 26, 31, 43, 45, 46,

    // "Fête du Génie"
    16, 55, 45, 31, 11, 30, 46, 11, 17, 54, 39, 35, 31,

    // "Fête du Travail"
    16, 55, 45, 31, 11, 30, 46, 11, 25, 43, 27, 47, 27, 35, 37,

    // "Fête de l'Opinion"
    16, 55, 45, 31, 11, 30, 31, 11, 37, 12, 20, 41, 35, 39, 35, 40, 39,

    // "Fête des Récompenses"
    16, 55, 45, 31, 11, 30, 31, 44, 11, 23, 54, 29, 40, 38, 41, 31, 39, 44, 31, 44,

    // "Fête de la Révolution"
    16, 55, 45, 31, 11, 30, 31, 11, 37, 27, 11, 23, 54, 47, 40, 37, 46, 45, 35, 40, 39,

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
    41, 40, 38, 38, 31, 11, 30, 31, 11, 45, 31, 43, 43, 31,

    // "immortelle"
    35, 38, 38, 40, 43, 45, 31, 37, 37, 31,

    // "potiron"
    41, 40, 45, 35, 43, 40, 39,

    // "réséda"
    43, 54, 44, 54, 30, 27,

    // "âne"
    52, 39, 31,

    // "belle de nuit"
    28, 31, 37, 37, 31, 11, 30, 31, 11, 39, 46, 35, 45,

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
    29, 34, 40, 46, 13, 32, 37, 31, 46, 43,

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
    54, 43, 27, 28, 37, 31, 11, 44, 46, 29, 43, 54,

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
    45, 31, 43, 43, 31, 11, 47, 54, 33, 54, 45, 27, 37, 31,

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
    41, 35, 31, 43, 43, 31, 11, 51, 11, 29, 34, 27, 46, 48,

    // "marbre"
    38, 27, 43, 28, 43, 31,

    // "van"
    47, 27, 39,

    // "pierre à plâtre"
    41, 35, 31, 43, 43, 31, 11, 51, 11, 41, 37, 52, 45, 43, 31,

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
    37, 27, 46, 43, 35, 31, 43, 13, 45, 35, 39,

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
    41, 31, 43, 29, 31, 13, 39, 31, 35, 33, 31,

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
    34, 55, 45, 43, 31, 11, 31, 39, 43, 27, 29, 35, 39, 54,

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
    28, 52, 45, 40, 39, 13, 30, 12, 40, 43,

    // "chamerisier"
    29, 34, 27, 38, 31, 43, 35, 44, 35, 31, 43,

    // "ver à soie"
    47, 31, 43, 11, 51, 11, 44, 40, 35, 31,

    // "consoude"
    29, 40, 39, 44, 40, 46, 30, 31,

    // "pimprenelle"
    41, 35, 38, 41, 43, 31, 39, 31, 37, 37, 31,

    // "corbeille d'or"
    29, 40, 43, 28, 31, 35, 37, 37, 31, 11, 30, 12, 40, 43,

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
    29, 27, 35, 37, 37, 31, 13, 37, 27, 35, 45,

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
    28, 40, 46, 35, 37, 37, 40, 39, 13, 28, 37, 27, 39, 29,

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
    54, 41, 35, 39, 31, 13, 47, 35, 39, 31, 45, 45, 31,

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
    47, 31, 43, 33, 31, 11, 30, 12, 40, 43,

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
    50, // annee: "année "
    56, // decade: " Décade "
    64, // on_off: "on"
    66, // "off"
    69, // months: "Vendémiaire"
    80, // "Brumaire"
    88, // "Frimaire"
    96, // "Nivôse"
    102, // "Pluviôse"
    110, // "Ventôse"
    117, // "Germinal"
    125, // "Floréal"
    132, // "Prairial"
    140, // "Messidor"
    148, // "Thermidor"
    157, // "Fructidor"
    166, // days: "Primidi"
    173, // "Duodi"
    178, // "Tridi"
    183, // "Quartidi"
    191, // "Quintidi"
    199, // "Sextidi"
    206, // "Septidi"
    213, // "Octidi"
    219, // "Nonidi"
    225, // "Décadi"
    231, // sansculottides: "Fête de la Vertu"
    247, // "Fête du Génie"
    260, // "Fête du Travail"
    275, // "Fête de l'Opinion"
    292, // "Fête des Récompenses"
    312, // "Fête de la Révolution"
    333, // day_of_year: "raisin"
    339, // "safran"
    345, // "châtaigne"
    354, // "colchique"
    363, // "cheval"
    369, // "balsamine"
    378, // "carotte"
    385, // "amarante"
    393, // "panais"
    399, // "cuve"
    403, // "pomme de terre"
    417, // "immortelle"
    427, // "potiron"
    434, // "réséda"
    440, // "âne"
    443, // "belle de nuit"
    456, // "citrouille"
    466, // "sarrasin"
    474, // "tournesol"
    483, // "pressoir"
    491, // "chanvre"
    498, // "pêche"
    503, // "navet"
    508, // "amaryllis"
    517, // "bœuf"
    521, // "aubergine"
    530, // "piment"
    536, // "tomate"
    542, // "orge"
    546, // "tonneau"
    553, // "pomme"
    558, // "céleri"
    564, // "poire"
    569, // "betterave"
    578, // "oie"
    581, // "héliotrope"
    591, // "figue"
    596, // "scorsonère"
    606, // "alisier"
    613, // "charrue"
    620, // "salsifis"
    628, // "macre"
    633, // "topinambour"
    644, // "endive"
    650, // "dindon"
    656, // "chervis"
    663, // "cresson"
    670, // "dentelaire"
    680, // "grenade"
    687, // "herse"
    692, // "bacchante"
    701, // "azerole"
    708, // "garance"
    715, // "orange"
    721, // "faisan"
    727, // "pistache"
    735, // "macjonc"
    742, // "coing"
    747, // "cormier"
    754, // "rouleau"
    761, // "raiponce"
    769, // "turneps"
    776, // "chicorée"
    784, // "nèfle"
    789, // "cochon"
    795, // "mâche"
    800, // "chou-fleur"
    810, // "miel"
    814, // "génépi"
    820, // "pioche"
    826, // "cire"
    830, // "raifort"
    837, // "cèdre"
    842, // "sapin"
    847, // "chevreuil"
    856, // "ajonc"
    861, // "cyprès"
    867, // "lierre"
    873, // "sabine"
    879, // "hoye"
    883, // "érable sucré"
    895, // "bruyère"
    902, // "roseau"
    908, // "oseille"
    915, // "grillon"
    922, // "pignon"
    928, // "liège"
    933, // "truffe"
    939, // "olive"
    944, // "pelle"
    949, // "tourbe"
    955, // "houille"
    962, // "bitume"
    968, // "soufre"
    974, // "chien"
    979, // "lave"
    983, // "terre végétale"
    997, // "fumier"
    1003, // "salpêtre"
    1011, // "fléau"
    1016, // "granite"
    1023, // "argile"
    1029, // "ardoise"
    1036, // "grès"
    1040, // "lapin"
    1045, // "silex"
    1050, // "marne"
    1055, // "pierre à chaux"
    1069, // "marbre"
    1075, // "van"
    1078, // "pierre à plâtre"
    1093, // "sel"
    1096, // "fer"
    1099, // "cuivre"
    1105, // "chat"
    1109, // "étain"
    1114, // "plomb"
    1119, // "zinc"
    1123, // "mercure"
    1130, // "crible"
    1136, // "lauréole"
    1144, // "mousse"
    1150, // "fragon"
    1156, // "pervenche"
    1165, // "taureau"
    1172, // "laurier-tin"
    1183, // "amatyste"
    1191, // "mézéréon"
    1199, // "peuplier"
    1207, // "coignée"
    1214, // "ellébore"
    1222, // "brocoli"
    1229, // "laurier"
    1236, // "avelinier"
    1245, // "vache"
    1250, // "buis"
    1254, // "lichén"
    1260, // "if"
    1262, // "pulmonaire"
    1272, // "serpette"
    1280, // "thlaspi"
    1287, // "thimelé"
    1294, // "chiendent"
    1303, // "traînasse"
    1312, // "lièvre"
    1318, // "guède"
    1323, // "noisetier"
    1332, // "cyclamen"
    1340, // "chélidoine"
    1350, // "traîneau"
    1358, // "tussilage"
    1367, // "cornouiller"
    1378, // "violier"
    1385, // "troène"
    1391, // "bouc"
    1395, // "asaret"
    1401, // "alaterne"
    1409, // "violette"
    1417, // "marceau"
    1424, // "bêche"
    1429, // "narcisse"
    1437, // "orme"
    1441, // "fumeterre"
    1450, // "vélar"
    1455, // "chèvre"
    1461, // "épinard"
    1468, // "doronic"
    1475, // "mouron"
    1481, // "cerfeuil"
    1489, // "cordeau"
    1496, // "mandragore"
    1506, // "persil"
    1512, // "cochléaria"
    1522, // "pâquerette"
    1532, // "thon"
    1536, // "pissenlit"
    1545, // "sylvie"
    1551, // "capillaire"
    1561, // "frêne"
    1566, // "plantoir"
    1574, // "primevère"
    1583, // "platane"
    1590, // "asperge"
    1597, // "tulipe"
    1603, // "poule"
    1608, // "bette"
    1613, // "bouleau"
    1620, // "jonquille"
    1629, // "aulne"
    1634, // "couvoir"
    1641, // "perce-neige"
    1652, // "crocus"
    1658, // "hêtre"
    1663, // "laitue"
    1669, // "torillon"
    1677, // "lilas"
    1682, // "anémone"
    1689, // "pensée"
    1695, // "myrtille"
    1703, // "greffoir"
    1711, // "cerisier"
    1719, // "verveine"
    1727, // "grenadier"
    1736, // "vernal"
    1742, // "cheval"
    1748, // "brenèche"
    1756, // "charme"
    1762, // "morille"
    1769, // "hêtre enraciné"
    1783, // "ruche"
    1788, // "rose"
    1792, // "chêne"
    1797, // "fougère"
    1804, // "aubépine"
    1812, // "rossignol"
    1821, // "ancolie"
    1828, // "muguet"
    1834, // "champignon"
    1844, // "hyacinthe"
    1853, // "râteau"
    1859, // "rhubarbe"
    1867, // "sainfoin"
    1875, // "bâton-d'or"
    1885, // "chamerisier"
    1896, // "ver à soie"
    1906, // "consoude"
    1914, // "pimprenelle"
    1925, // "corbeille d'or"
    1939, // "arroche"
    1946, // "sarcloir"
    1954, // "statice"
    1961, // "fritillaire"
    1972, // "bourache"
    1980, // "valériane"
    1989, // "carpe"
    1994, // "fusain"
    2000, // "civette"
    2007, // "buglosse"
    2015, // "sénevé"
    2021, // "houlette"
    2029, // "luzerne"
    2036, // "hémérocalle"
    2047, // "trèfle"
    2053, // "angélique"
    2062, // "canard"
    2068, // "mélisse"
    2075, // "fromental"
    2084, // "martagon"
    2092, // "serpolet"
    2100, // "faux"
    2104, // "fraise"
    2110, // "bétoine"
    2117, // "pois"
    2121, // "acacia"
    2127, // "caille"
    2133, // "œillet"
    2139, // "sureau"
    2145, // "pavot"
    2150, // "tilleul"
    2157, // "fourche"
    2164, // "barbeau"
    2171, // "camomille"
    2180, // "chévrefeuille"
    2193, // "caille-lait"
    2204, // "tanche"
    2210, // "jasmin"
    2216, // "verveine"
    2224, // "thym"
    2228, // "pivoine"
    2235, // "chariot"
    2242, // "seigle"
    2248, // "avoine"
    2254, // "oignon"
    2260, // "véronique"
    2269, // "mulet"
    2274, // "romaine"
    2281, // "concombre"
    2290, // "échalote"
    2298, // "absinthe"
    2306, // "faucille"
    2314, // "coriandre"
    2323, // "artichaut"
    2332, // "girofle"
    2339, // "lavande"
    2346, // "chamois"
    2353, // "tabac"
    2358, // "groseille"
    2367, // "gesse"
    2372, // "cerise"
    2378, // "parc"
    2382, // "menthe"
    2388, // "cumin"
    2393, // "haricot"
    2400, // "orcanète"
    2408, // "pintade"
    2415, // "sauge"
    2420, // "ail"
    2423, // "vesce"
    2428, // "blé"
    2431, // "chalémie"
    2439, // "épeautre"
    2447, // "bouillon-blanc"
    2461, // "melon"
    2466, // "ivraie"
    2472, // "bélier"
    2478, // "prêle"
    2483, // "armoise"
    2490, // "carthame"
    2498, // "mûre"
    2502, // "arrosoir"
    2510, // "panis"
    2515, // "salicorne"
    2524, // "abricot"
    2531, // "basilic"
    2538, // "brebis"
    2544, // "guimauve"
    2552, // "lin"
    2555, // "amande"
    2561, // "gentiane"
    2569, // "écluse"
    2575, // "carline"
    2582, // "câprier"
    2589, // "lentille"
    2597, // "aunée"
    2602, // "loutre"
    2608, // "myrte"
    2613, // "colza"
    2618, // "lupin"
    2623, // "coton"
    2628, // "moulin"
    2634, // "prune"
    2639, // "millet"
    2645, // "lycoperdon"
    2655, // "escourgeon"
    2665, // "saumon"
    2671, // "tubéreuse"
    2680, // "sucrion"
    2687, // "apocyn"
    2693, // "réglisse"
    2701, // "échelle"
    2708, // "pastèque"
    2716, // "fenouil"
    2723, // "épine-vinette"
    2736, // "noix"
    2740, // "truite"
    2746, // "citron"
    2752, // "cardère"
    2759, // "nerprun"
    2766, // "tagette"
    2773, // "hotte"
    2778, // "églantier"
    2787, // "noisette"
    2795, // "houblon"
    2802, // "sorgho"
    2808, // "écrevisse"
    2817, // "bigarade"
    2825, // "verge d'or"
    2835, // "maïs"
    2839, // "marron"
    2845, // "panier"
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
    6, // annee: "année "
    8, // decade: " Décade "
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
    78, // '1'
    156, // '2'
    234, // '3'
    312, // '4'
    390, // '5'
    468, // '6'
    546, // '7'
    624, // '8'
    702, // '9'
    780, // ':'
};

// big font content (bitmap data, packed)
const std::array<uint8_t, 819> big_font_content = {
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
    0x00,
    0x00,
    0x00,
    0x07,
    0xC0,
    0x1F,
    0xE0,
    0x1F,
    0xF0,
    0x3C,
    0x78,
    0x38,
    0x78,
    0x78,
    0x38,
    0x78,
    0x3C,
    0x70,
    0x3C,
    0x70,
    0x3C,
    0x70,
    0x3C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x3C,
    0x70,
    0x3C,
    0x70,
    0x3C,
    0x70,
    0x3C,
    0x78,
    0x3C,
    0x78,
    0x38,
    0x78,
    0x78,
    0x3C,
    0x78,
    0x3F,
    0xF0,
    0x1F,
    0xE0,
    0x07,
    0xC0,

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
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0xC0,
    0x07,
    0xC0,
    0x0F,
    0xC0,
    0x1F,
    0xC0,
    0x3F,
    0xC0,
    0x7B,
    0xC0,
    0xF3,
    0xC0,
    0x63,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,

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
    0x00,
    0x00,
    0x00,
    0x0F,
    0xC0,
    0x3F,
    0xE0,
    0xFF,
    0xF0,
    0x78,
    0xF8,
    0x20,
    0x78,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0xF0,
    0x01,
    0xE0,
    0x01,
    0xE0,
    0x03,
    0xC0,
    0x07,
    0x80,
    0x07,
    0x80,
    0x0F,
    0x00,
    0x1E,
    0x00,
    0x3E,
    0x00,
    0x3C,
    0x00,
    0x78,
    0x00,
    0xFF,
    0xFC,
    0xFF,
    0xFC,
    0xFF,
    0xFC,

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
    0x00,
    0x00,
    0x00,
    0x0F,
    0xC0,
    0x3F,
    0xF0,
    0xFF,
    0xF0,
    0x70,
    0xF8,
    0x20,
    0x78,
    0x00,
    0x38,
    0x00,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x78,
    0x00,
    0x78,
    0x01,
    0xF0,
    0x1F,
    0xE0,
    0x1F,
    0xC0,
    0x1F,
    0xF0,
    0x00,
    0xF8,
    0x00,
    0x78,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x80,
    0x7C,
    0xE0,
    0xF8,
    0xFF,
    0xF0,
    0xFF,
    0xE0,
    0x3F,
    0x80,

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
    0x00,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x01,
    0xF0,
    0x01,
    0xF0,
    0x03,
    0xF0,
    0x03,
    0x70,
    0x07,
    0x70,
    0x07,
    0x70,
    0x0E,
    0x70,
    0x0E,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x38,
    0x70,
    0x38,
    0x70,
    0x70,
    0x70,
    0xF0,
    0x70,
    0xE0,
    0x70,
    0xFF,
    0xFE,
    0xFF,
    0xFE,
    0xFF,
    0xFE,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0x70,

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
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x7F,
    0xF0,
    0x7F,
    0xF0,
    0x7F,
    0xF0,
    0x70,
    0x00,
    0x70,
    0x00,
    0x70,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xFF,
    0x80,
    0xFF,
    0xE0,
    0xFF,
    0xF0,
    0x41,
    0xF0,
    0x00,
    0xF8,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x78,
    0x80,
    0xF0,
    0xC1,
    0xF0,
    0xFF,
    0xE0,
    0xFF,
    0xC0,
    0x7F,
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
    0x00,
    0x00,
    0x00,
    0x01,
    0xF8,
    0x07,
    0xF8,
    0x0F,
    0xF8,
    0x1F,
    0x00,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x38,
    0x00,
    0x78,
    0x00,
    0x70,
    0x00,
    0x73,
    0xE0,
    0x77,
    0xF0,
    0x7F,
    0xF8,
    0x7C,
    0x78,
    0xF8,
    0x3C,
    0xF8,
    0x3C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0x70,
    0x1C,
    0x70,
    0x1C,
    0x78,
    0x3C,
    0x78,
    0x3C,
    0x38,
    0x3C,
    0x3C,
    0x78,
    0x1F,
    0xF8,
    0x0F,
    0xF0,
    0x07,
    0xC0,

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
    0x00,
    0x00,
    0x00,
    0x00,
    0xFF,
    0xFC,
    0xFF,
    0xFC,
    0xFF,
    0xFC,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x70,
    0x00,
    0xF0,
    0x00,
    0xF0,
    0x00,
    0xE0,
    0x01,
    0xE0,
    0x01,
    0xE0,
    0x01,
    0xC0,
    0x03,
    0xC0,
    0x03,
    0xC0,
    0x07,
    0x80,
    0x07,
    0x80,
    0x07,
    0x80,
    0x0F,
    0x00,
    0x0F,
    0x00,
    0x0F,
    0x00,
    0x1E,
    0x00,
    0x1E,
    0x00,
    0x3E,
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
    0x00,
    0x00,
    0x00,
    0x0F,
    0xC0,
    0x1F,
    0xF0,
    0x3F,
    0xF8,
    0x7C,
    0x78,
    0x78,
    0x3C,
    0x78,
    0x3C,
    0x70,
    0x3C,
    0x78,
    0x3C,
    0x78,
    0x38,
    0x3C,
    0x78,
    0x3E,
    0xF0,
    0x1F,
    0xE0,
    0x0F,
    0xC0,
    0x1F,
    0xE0,
    0x3C,
    0xF0,
    0x78,
    0x78,
    0x70,
    0x3C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0xF0,
    0x1C,
    0x70,
    0x3C,
    0x78,
    0x7C,
    0x7F,
    0xF8,
    0x3F,
    0xF0,
    0x0F,
    0xC0,

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
    0x00,
    0x00,
    0x00,
    0x0F,
    0xC0,
    0x1F,
    0xE0,
    0x3F,
    0xF0,
    0x7C,
    0x78,
    0x78,
    0x78,
    0x70,
    0x38,
    0xF0,
    0x3C,
    0xF0,
    0x3C,
    0xF0,
    0x3C,
    0xF0,
    0x3C,
    0xF0,
    0x3C,
    0x78,
    0x3C,
    0x78,
    0x7C,
    0x3F,
    0xDC,
    0x3F,
    0xDC,
    0x0F,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x3C,
    0x00,
    0x38,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0xF0,
    0x41,
    0xF0,
    0x3F,
    0xE0,
    0x3F,
    0xC0,
    0x3F,
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
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x70,
    0xF0,
    0xF8,
    0xF0,
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
    0x00,
    0x70,
    0xF0,
    0xF8,
    0xF0,
    0x70
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
    360, // 'B'
    408, // 'D'
    456, // 'F'
    480, // 'G'
    528, // 'M'
    576, // 'N'
    624, // 'O'
    672, // 'P'
    696, // 'Q'
    744, // 'R'
    792, // 'S'
    816, // 'T'
    864, // 'V'
    912, // 'a'
    936, // 'b'
    960, // 'c'
    984, // 'd'
    1008, // 'e'
    1032, // 'f'
    1056, // 'g'
    1080, // 'h'
    1104, // 'i'
    1128, // 'j'
    1152, // 'l'
    1176, // 'm'
    1224, // 'n'
    1248, // 'o'
    1272, // 'p'
    1296, // 'q'
    1320, // 'r'
    1344, // 's'
    1368, // 't'
    1392, // 'u'
    1416, // 'v'
    1464, // 'x'
    1488, // 'y'
    1536, // 'z'
    1560, // 'à'
    1584, // 'â'
    1608, // 'è'
    1632, // 'é'
    1656, // 'ê'
    1680, // 'î'
    1704, // 'ï'
    1728, // 'ô'
    1752, // 'û'
    1776, // 'œ'
    1824, // '🔔' (custom bell bitmap)
};

// normal font content (bitmap data, packed)
const std::array<uint8_t, 1872> normal_font_content = {
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
