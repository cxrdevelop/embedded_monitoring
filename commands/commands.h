#ifndef COMMANDS_H
#define COMMANDS_H

typedef enum {
    // System
    CommandType_Reset,
    CommandType_Save,
    CommandType_Factory,
    CommandType_GetVersion,

    // Monitoring
    CommandType_EnalbeSMS,          // выключить СМС на время работы с настройками
    CommandType_EnableMonitoring,   // выключить мониторинг
    CommandType_ResetActions,       // Сбросить все действия
    CommandType_ApplySettings,      // Переписать все настройки из Shadow памяти в основную
                                    // (??? решает проблему лажных срабатываний когда работаем с настройками)
                                    // (или это может быть решено путем выключения мониторинга)

    // Status

    // Trigger table
    CommandType_Trigger_GetSize,
    CommandType_Trigger_GetCapacity,
    CommandType_Trigger_Add,
    CommandType_Trigger_Remove,
    CommandType_Trigger_ClearAll,
    CommandType_Trigger_Get,
    CommandType_Trigger_Set,

    // Action table
    CommandType_Action_GetSize,
    CommandType_Action_GetCapacity,
    CommandType_Action_Add,
    CommandType_Action_Remove,
    CommandType_Action_ClearAll,
    CommandType_Action_Get,
    CommandType_Action_Set,

    // Encoder table
    CommandType_Encoder_GetSize,
    CommandType_Encoder_GetCapacity,
    CommandType_Encoder_Add,
    CommandType_Encoder_Remove,
    CommandType_Encoder_ClearAll,
    CommandType_Encoder_Get,
    CommandType_Encoder_Set
} CommandType;

#define DATA_SIZE 255

typedef struct {
    CommandType type;
    int ack;
    int dataSize;
    char data[DATA_SIZE];
} command_t;

// Вопрос - как передать данные в команде? Максимальный размер - текст для смс.

#endif // COMMANDS_H
